#include <iostream>
#include <string>
#include <vector>
#include <math.h>

struct Point{
    Point(double XComponent, double YComponent){
        x = XComponent;
        y = YComponent;
    }
    double x;
    double y;
};

class Matrix{
    public:
        Matrix(Point pMin, Point pMax, std::vector<int> dimensions){
            xDist = pMax.x - pMin.y;
            yDist = pMax.y - pMin.y;
    
            int d[3] = {dimensions[0], dimensions[1], dimensions[0]*dimensions[1]};

            xSpacing = xDist/(d[0]-1);
            ySpacing = yDist/(d[1]-1);

            


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
            
            data.reserve(d[2]);
            
            for(int i = 0; i < d[2]; i++){
                data[i].reserve(2);
                for(int j = 0; j < 2; j++){
                    if(j == 0){
                        data[i][j] = xList[i];
                    } else {
                        data[i][j] = yList[i];
                    }
                }
            }
        }
        const std::vector <std::vector<double>>& getMatrix(){
            return data;
        }
    private:
        std::vector<double> matrixX;
        std::vector<double> matrixY;
        double xDist;
        double yDist;
        double xSpacing;
        double ySpacing;
        std::vector<double> xList;
        std::vector<double> yList;
        std::vector <std::vector<double>> data;
};

int main()
{
    std::cout << "test";
    Matrix m(Point (-10,-10), Point (10,10), {5,5});
    auto& d = m.getMatrix();
    for(auto& out : d){
        std::cout << out[0] << std::endl;
        std::cout << out[1] << std::endl;
    }
    return 0;   
}