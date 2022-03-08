# import numpy as np
import math

YMax = 1
YMin = -1
XMax = 1
XMin = -1

D = [6,7] # x, y

XDist = XMax - XMin
YDist = YMax - YMin

XSpacing = XDist/(D[0]-1)
YSpacing = YDist/(D[1]-1)

MatrixX = []
MatrixY = []

for i in range(D[0]):
    MatrixX.append(i*XSpacing)
for i in range(D[1]):
    MatrixY.append(i*YSpacing)

Md = [int(x) for x in str(D[0]*D[1])]

MatrixXY = [(MatrixX[((x - 1) % D[0]) + 1],MatrixY[math.floor((x - 1)/D[0])]) for x in Md]

print(MatrixXY)