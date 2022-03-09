# from Approximater import *
from Matrix import *
import matplotlib.pyplot as plt

YMax = 1
YMin = -1
XMax = 1
XMin = -1

D = [2,3] # x, y

MatrixXY = Matrix_Generator(XMin,XMax,YMax,YMin,D)

print(MatrixXY.x)

r = min((XMax-XMin)/(2*(D[0]-1)),(YMax-YMin)/(2*(D[1]-1)))*0.9



## Soon TM