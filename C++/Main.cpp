#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Matrix{
    public: 
        Matrix(point PMin, point PMax, int D[2]){
            XDist = PMax.x - PMin.y;
            YDist = PMax.y - PMin.y;
            
            D[3] = D[0]*D[1];

            XSpacing = XDist/(D[0]-1);
            YSpacing = YDist/(D[1]-1);

            for(int i = 0; i < D[0]; i++){
                MatrixX[i] = (i*XSpacing + PMin.x);
            }
            for(int i = 0; i < D[1]; i++){
                MatrixY[i] = (i*YSpacing + PMin.y);
            }
            for(int i = 0; i < D[2]; i++){
                XList[i] = MatrixX[i % D[0]];
                YList[i] = MatrixY[floor(i/D[0])];
            }
            
            
        };
    private:
        double MatrixX[D[0]];
        double MatrixY[D[1]];
        double XDist;
        double YDist;
        double XSpacing;
        double YSpacing;
        double XList[D[2]];
        double YList[D[2]];

};
class point{
    point(double XComponent, double YComponent){
        x = XComponent;
        y = YComponent;
    }
    public:
        double x;
        double y;
};

int main()
{
    cout << "Test"; 
    return 0;   
}