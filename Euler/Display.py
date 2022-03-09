from Approximater import *
from Matrix import *
import matplotlib.pyplot as plt

YMax = 2
YMin = -2
XMax = 2
XMin = -2

D = [50,50]
D = [D[0],D[1],D[0]*D[1]] # x, y, x*y

MatrixXY = Matrix_Generator(XMin,XMax,YMax,YMin,D)

r = min((XMax-XMin)/(2*(D[0]-1)),(YMax-YMin)/(2*(D[1]-1)))*0.9

k = [r/((m(MatrixXY.x[i],MatrixXY.y[i])**2 + 1)**(1/2)) for i in range(D[2])]

MasterX = []
MasterY = []

for i in range(D[2]):
    MasterX.append([MatrixXY.x[i] - k[i], MatrixXY.x[i] + k[i]])
    MasterY.append([MatrixXY.y[i] - m(MatrixXY.x[i],MatrixXY.y[i])*k[i], MatrixXY.y[i] + m(MatrixXY.x[i],MatrixXY.y[i])*k[i]])

MasterXY = Matrix(MasterX,MasterY)

plt.figure(figsize=(8,8), facecolor='grey')
plt.rcParams.update({'axes.facecolor':'black'})
plt.subplots_adjust(left=0.04,bottom=0.04,right=0.99,top=0.99)


for i in range(D[2]):
    plt.plot(MasterXY.x[i],MasterXY.y[i], color='grey')

Kx = (XMax - XMin)/(6*D[0])
Ky = (YMax - YMin)/(6*D[1])

YBoundsUpper1 = max([m(MatrixXY.x[i],YMax)*k[i] for i in range(D[2] - D[0] + 1, D[2])])
YBoundsUpper2 = max([m(MatrixXY.x[i],YMax)*(-k[i]) for i in range(D[2] - D[0] + 1, D[2])])

YBoundsUpper = max(YBoundsUpper1, YBoundsUpper2) + YMax + Ky

YBoundsLower1 = min([m(MatrixXY.x[i],YMin)*k[i] for i in range(1, D[1])])
YBoundsLower2 = min([m(MatrixXY.x[i],YMin)*(-k[i]) for i in range(1, D[1])])

YBoundsLower = min(YBoundsLower1, YBoundsLower2) + YMin - Ky

YBounds = [YBoundsLower, YBoundsUpper]

XBounds = [min([MatrixXY.x[i] - k[i] for i in range(D[2])]) - Kx, max([MatrixXY.x[i] + k[i] for i in range(D[2])]) + Kx]

plt.xlim(XBounds)
plt.ylim(YBounds)

plt.show()