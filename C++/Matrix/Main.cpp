#include <iostream>
#include <string>
#include <vector>
#include <math.h>

struct Point{
    Point(): x(0),y(0){

    }
    Point(double XComponent, double YComponent){
        x = XComponent;
        y = YComponent;
    }
    double x;
    double y;
    friend std::ostream& operator << (std::ostream& os, const Point& p);
    Point operator + (const Point& p){
        Point p2;
        p2.x = this->x + p.x;
        p2.y = this->y + p.y;
        return p2;
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

int main()
{
/*  Matrix m(Point (-10,-10), Point (10,10), {21,21});
    auto& d = m.getMatrix();
    for(auto& out : d){
        std::cout << out;
    }  */
    Point p1(1,4);
    Point p2(2,3);
    std::cout << (p1 + p2);
    return 0;   
}