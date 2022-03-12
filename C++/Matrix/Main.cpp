#include <iostream>
#include <string>
#include <vector>
#include <math.h>

struct Point{
    Point(): x(0),y(0){}
    Point(double XComponent, double YComponent){
        x = XComponent;
        y = YComponent;
    }
    double x;
    double y;
    friend std::ostream& operator << (std::ostream& os, const Point& p);
    Point operator + (const Point& p){
        Point pSum;
        pSum.x = this->x + p.x;
        pSum.y = this->y + p.y;
        return pSum;
    }
};

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
};

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

/*
class SlopeField{
    public: 
        SlopeField(Point pMin, Point pMax, std::vector<int> dimensions){
            Matrix matrix (Point pMin, Point pMax, std::vector<int> dimensions);

        }
        const std::vector <Point>& getMatrix(){
            return data;
        }

    private:
}; */


class SlopeField : private Matrix{
    public:
        SlopeField(Point pMin, Point pMax, std::vector<int> dimensions){
            Matrix matrix = Matrix(pMin, pMax, dimensions);
            // data = matrix.getMatrix;
        }
    private:
        std::vector <Point> data;
};




/*
class Matrix{
    public:
        Matrix(Point pMin, Point pMax, std::vector<int> dimensions){
            xDist = pMax.x - pMin.y;
            yDist = pMax.y - pMin.y;

            startMin = pMin;
            startMax = pMax;
    
            d = {dimensions[0], dimensions[1], dimensions[0]*dimensions[1]};

            double xSpacing = xDist/(d[0]-1);
            double ySpacing = yDist/(d[1]-1);

            std::vector<double> matrixX;
            std::vector<double> matrixY;
            std::vector<double> xList;
            std::vector<double> yList;

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
        std::vector <Segment>& getSegments(){
            std::vector <Segment> segments;
            double r = std::min(xDist/(2*d[0]-1),yDist/(2*d[1]-1));
            std::vector <double> k;

            for(int i = 0; i < d[2]; i++){
/*                  *<--->.<--->* 
                    |  k  |  k  | -- k = dist
                    * = p1|     * = p2
                          . = data[i]        */ /*
                k.push_back(r/pow(pow(m(data[i].x,data[i].y), 2) + 1, 1/2));
                // points in seg
                Point pMin (data[i].x - k[i], data[i].y - m(data[i].x,data[i].y)*k[i]);
                Point pMax (data[i].x + k[i], data[i].y + m(data[i].x,data[i].y)*k[i]);
                // seg list construct
                segments.push_back(Segment(pMin, pMax));
            }
            return segments;
        }
        std::vector <Point>& getBounds(){
            Point boundMin;
            Point boundMax;

            double xK = xDist/(6*d[0]);
            double yK = yDist/(6*d[1]);

            std::vector <double> yUpperBounds1;
            std::vector <double> yUpperBounds2;

            std::vector <double> yLowerBounds1;
            std::vector <double> yLowerBounds2;

            double yUpperBounds;
            double yLowerBounds;

            for(int i = d[2] - d[0] + 1; i < d[2]; i++){
                yUpperBounds1.push_back(m(data[i].x,startMin.y)*k[i]);

            }

            std::vector <Point> out = {boundMin, boundMax};
            return out;
        }

    private:
        std::vector <Point> data;
        double yDist;
        double xDist;
        std::vector<int> d;
        Point startMin;
        Point startMax;

};
*/
double m(double x, double y){
    return (pow(x,2) + pow(y,2) - 2*x*y - 3);  // x^2 + y^2 - 2xy - 3
}

Point StartSelect(){
    double startX;
    double startY;
    // questions
    std::cout << "Start X: ";
    std::cin >> startX;
    std::cout << "Start Y: ";
    std::cin >> startY;
    Point startPoint(startX,startY);

    return startPoint;
}



std::vector<double> NHSelect(double targetX, double x){
    std::vector<double> out;
    std::cout << "N or H: (n/h) ";
    char nhSelect;
    double n;
    double h;
    std::cin >> nhSelect;
    if(tolower(nhSelect) == 'n'){
        std::cout << "N: ";
        std::cin >> n;
        if(n > 1000000){
            std::cout << "N > 1,000,000 -- reset to 1000000 \n";
            n = 1000000;
        } else if(n <= 0){
            std::cout << "N <= 0, reset to 1000000";
            n = 1000000;
        }
        h = (targetX-x)/n;
    } else if(tolower(nhSelect) == 'h'){
        std::cout << "H: ";
        std::cin >> h;
        n = (targetX-x)/h;
        if(n > 1000000){
            std::cout << "N > 1,000,000 -- reset to 1000000 \n";
            n = 1000000;
            h = (targetX-x)/n;
        } else if(n <= 0){
            std::cout << "N <= 0, reset to 1000000";
            n = 1000000;
        }
    } else {
        std::cout << "Invalid char" << std::endl;
        out = NHSelect(targetX, x);
    }
    out.push_back(n);
    out.push_back(h);
    return out;
}


std::vector<Point> Approximate(/*Point startPoint*/){
    Point startPoint = StartSelect();
    std::vector<Point> pointList = {startPoint};

    std::vector<double> k;
    double targetX;
    std::cout << "Target X: ";
    std::cin >> targetX;

    std::vector<double> nh = NHSelect(targetX, startPoint.x);
    int n = (int)nh[0];
    double h = nh[1];

    for(int i = 0; i < n; i++){
        pointList.push_back(Point (pointList[i].x + h, pointList[i].y + m(pointList[i].x,pointList[i].y)*h));
    }
    return pointList;
}



int main()
{
/*  
    Matrix m(Point (-10,-10), Point (10,10), {21,21});
    auto& d = m.getMatrix();
    for(auto& out : d){
        std::cout << out;
    }  
*/
    
    

    return 0;   
}