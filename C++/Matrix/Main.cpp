#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <optional>

double slope(double x, double y){
    return (pow(x,2) + pow(y,2) - 2*x*y - 3);  // x^2 + y^2 - 2xy - 3
}

struct Point{
    Point(): x(0),y(0){}
    Point(double XComponent, double YComponent){
        x = XComponent;
        y = YComponent;
    }    
    double x;
    double y;

    friend std::ostream& operator << (std::ostream& os, const Point& p);
    friend bool operator < (const Point& l, const Point& r);

    Point operator + (const Point& p){
        Point pSum;
        pSum.x = this->x + p.x;
        pSum.y = this->y + p.y;
        return pSum;
    }
};

bool operator < (const Point& l, const Point& r){
    return l.x < r.x && l.y < r.y;
}

std::ostream& operator << (std::ostream& os, const Point& p){
    os << "(" << p.x << ", " << p.y << ")" << std::endl;
    return os;
}

struct Segment{
    Segment() = default;
    Segment(Point point1, Point point2){
        p1 = point1;
        p2 = point2;
    }
    Point p1;
    Point p2;
    friend bool operator < (const Segment& l, const Segment& r);
};

bool operator < (const Segment& l, const Segment& r){
    return l.p1 < r.p1 && l.p2 < r.p2;
}

/*
template <typename T>
class container{
    T x;
    T y;
};
*/

class Matrix{
    public:
        Matrix(): data(0){}
        Matrix(Point pMin, Point pMax, std::vector<int> dimensions){
            xDist = pMax.x - pMin.y;
            yDist = pMax.y - pMin.y;

            startMin = pMin;
            startMax = pMax;
    
            d = {dimensions[0], dimensions[1], dimensions[0]*dimensions[1]};

            double xSpacing = xDist/(d[0]-1);
            double ySpacing = yDist/(d[1]-1);

            for(int i = 0; i < d[0]; i++){
                matrixX.push_back(i*xSpacing + pMin.x); 
            }
            for(int i = 0; i < d[1]; i++){
                matrixY.push_back(i*ySpacing + pMin.y);
            }
            for(int i = 0; i < d[2]; i++){
                xList.push_back(matrixX[i % d[0]]);
                yList.push_back(matrixY[floor(i/d[0])]);
            }
            
            data.resize(d[2]);
            
            for(int i = 0; i < d[2]; i++){
                data.emplace_back(Point(xList[i],yList[i]));
            }
        }
        const std::vector <Point>& getMatrix(){
            return data;
        }
    protected:
        std::vector <Point> data;
        double yDist;
        double xDist;
        std::vector<int> d;
        Point startMin;
        Point startMax;
        std::vector<double> matrixX;
        std::vector<double> matrixY;
        std::vector<double> xList;
        std::vector<double> yList;  
};

class SlopeField : public Matrix{
    public:
        SlopeField(Point pMin, Point pMax, std::vector<int> dimensions) : Matrix(pMin, pMax, dimensions){
            genSegments();
        }
        const std::vector <Segment>& getSegments() const {
            return segments;
        }
        const std::vector <Point>& getBounds () const {
            return bounds;
        }
    private:
        void genSegments(){ // *Also gens bounds
            double r = std::min(xDist/(2*d[0]-1),yDist/(2*d[1]-1));
            std::vector <double> k;
            std::optional <Point> pLow;
            std::optional <Point> pHigh;            

            for(int i = 0; i < d[2]; i++){
            /*  k explination:
          diagram - *<--->.<--->* 
                    |  k  |  k  | -- k = dist
                    * = p1|     * = p2
                          . = data[i]
            */  k.push_back(r/pow(pow(slope(data[i].x,data[i].y), 2) + 1, 1/2));

                // Defining points in segment
                Point pMin (data[i].x - k[i], data[i].y - slope(data[i].x,data[i].y)*k[i]);
                Point pMax (data[i].x + k[i], data[i].y + slope(data[i].x,data[i].y)*k[i]);

                // Evaluating bounds
                for(auto* pTest : std::vector<std::optional <Point>*> {&pLow, &pHigh}){
                    if(!pTest->has_value()){
                        *pTest = pMin;
                    } else {
                        for(Point pCurr : {pMin, pMax}){
                            if(pTest->value().x < pCurr.x){
                                pTest->value().x = pCurr.x;
                            }
                            if(pTest->value().y < pCurr.y){
                                pTest->value().y = pCurr.y;
                            }
                        }
                    }
                }

                // Constructing Segment list
                segments.push_back(Segment(pMin, pMax));

            }

            // Constructing bounds list
            bounds.push_back(pLow.value());
            bounds.push_back(pHigh.value());
        }

        std::vector <Point> data;
        std::vector <Segment> segments;
        std::vector <Point> bounds;
};


std::vector <double> StartSelect(){
    double startX;
    double startY;
    double targetX;
    // questions
    std::cout << "Start X: ";
    std::cin >> startX;
    std::cout << "Start Y: ";
    std::cin >> startY;
    std::cout << "Target X: ";
    std::cin >> targetX;
    std::vector <double> out = {startX, startY, targetX};

    return out;
}



std::vector<double> NHSelect(double targetX, double x){
    std::vector<double> out;
    std::cout << "N or H: ";
    char nhSelect;
    std::cin >> nhSelect;
    double n;
    double h;
    double nCap = 10000000;
    if(tolower(nhSelect) == 'n'){
        std::cout << "N: ";
        std::cin >> n;
        if(n > nCap){
            std::cout << "N > " << nCap << " -- reset to " << nCap << std::endl;
            n = nCap;
        } else if(n <= 0){
            std::cout << "N <= 0, reset to " << nCap << std::endl;
            n = nCap;
        }
        h = (targetX-x)/n;
        std::cout << "H = " << h << std::endl;
    } else if(tolower(nhSelect) == 'h'){
        std::cout << "H: ";
        std::cin >> h;
        n = (targetX-x)/h;
        if(n > nCap){
            std::cout << "N > " << nCap << " -- reset to " << nCap << std::endl;
            n = nCap;
            h = (targetX-x)/n;
            std::cout << "H = " << h << std::endl;
        } else if(n <= 0){
            std::cout << "N <= 0, reset to " << nCap << std::endl;
            n = nCap;
            h = (targetX-x)/n;
            std::cout << "H = " << h << std::endl;            
        }
    } else if(nhSelect == 'm'){
        n = nCap;
        h = (targetX-x)/n;
        std::cout << "Max N selected, N set to " << nCap << std::endl << "H set to " << h << std::endl;
    } else {
        std::cout << "Invalid char" << std::endl;
        out = NHSelect(targetX, x);
    }
    out.push_back(n);
    out.push_back(h);
    return out;
}


std::vector<Point> Approximate(std::vector <double> in){
    Point startPoint (in[0],in[1]);
    std::vector<Point> pointList = {startPoint};

    std::vector<double> k;
    double targetX = in[2];

    std::vector<double> nh = NHSelect(targetX, startPoint.x);
    int n = (int)nh[0];
    double h = nh[1];

    for(int i = 0; i < n; i++){
        pointList.push_back(Point (pointList[i].x + h, pointList[i].y + slope(pointList[i].x,pointList[i].y)*h));
    }
    return pointList;
}



int main()
{
    std::vector <Point> pL = Approximate(StartSelect());
    std::cout << pL[pL.size() - 1];
    
    return 0;   
}