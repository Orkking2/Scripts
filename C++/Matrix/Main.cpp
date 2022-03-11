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
    void setPoint(double xComponent, double yComponent){
        x = xComponent;
        y = yComponent;
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

class Matrix{
    public:
        Matrix(Point pMin, Point pMax, std::vector<int> dimensions){
            double xDist = pMax.x - pMin.y;
            double yDist = pMax.y - pMin.y;
    
            int d[3] = {dimensions[0], dimensions[1], dimensions[0]*dimensions[1]};

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
            
            data_.resize(d[2]);
            
            for(int i = 0; i < d[2]; i++){
                data_.emplace_back(Point(xList[i],yList[i]));
            }
        }
        const std::vector <Point>& getMatrix(){
            return data_;
        }
    private:
        std::vector <Point> data_;
};

double m(double x, double y){
    return (pow(x,2) + pow(y,2) - 2*x*y - 3);  // x**2 + y**2 - 2*x*y - 3
}

Point StartSelect(){
    double startX;
    double startY;
    // questions
    std::cout << "Start X: ";
    std::cin >> startX;
    std::cout << std::endl << "Start Y: ";
    std::cin >> startY;
    Point startPoint(startX,startY);

    return startPoint;
}



std::vector<double> NHSelect(double targetX, double x){
    std::vector<double> out_;
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
        out_ = NHSelect(targetX, x);
    }
    out_.push_back(n);
    out_.push_back(h);
    return out_;
}


std::vector<Point> Approximate(/*Point startPoint*/){
    Point startPoint = StartSelect();
    std::vector<Point> point = {startPoint};

    std::vector<double> k;
    double targetX;
    std::cout << "Target X: ";
    std::cin >> targetX;

    std::vector<double> nh = NHSelect(targetX, startPoint.x);
    int n = (int)nh[0];
    double h = nh[1];

    for(int i = 0; i < n; i++){
        point.push_back(Point (point[i].x + h, point[i].y + m(point[i].x,point[i].y)*h));
    }

    return point;
}

int main()
{
/*  Matrix m(Point (-10,-10), Point (10,10), {21,21});
    auto& d = m.getMatrix();
    for(auto& out : d){
        std::cout << out;
    }  */
    
    auto disp = Approximate();
    for(auto out : disp){
        std::cout << out;
    }

    return 0;   
}