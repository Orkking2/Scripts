import numpy as np

YMax = 1
YMin = -1
XMax = 1
XMin = -1

D = [6,7] # x, y

XDist = XMax - XMin
YDist = YMax - YMin

XSpacing = XDist/(D[0]-1)
YSpacing = YDist/(D[1]-1)

XMatrix = []
YMatrix = []

for i in range(D[0]):
    XMatrix.append(i*XSpacing)
for i in range(D[1]):
    YMatrix.append(i*YSpacing)

