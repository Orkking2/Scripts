from Approximater import *
from Matrix import *
import matplotlib.pyplot as plt

YMax = 1
YMin = -1
XMax = 1
XMin = -1

D = [2,3,D[0]*D[1]] # x, y

MatrixXY = Matrix_Generator(XMin,XMax,YMax,YMin,D)

r = min((XMax-XMin)/(2*(D[0]-1)),(YMax-YMin)/(2*(D[1]-1)))*0.9

k = [r/((m(MatrixXY.x[x],MatrixXY.y[x])**2 + 1)**(1/2)) for x in range(D[2])]

MasterX = []
MasterY = []

for i in range(D[2]):
    MasterX.append()

MasterXY = Matrix(MasterX,MasterY)

for i in range(D[2]):
    plt.plot(MasterXY.x,MasterXY.y)
# plt.show()

print(k)

## Soon TM