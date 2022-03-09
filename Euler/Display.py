from Approximater import *
from Matrix import *
import matplotlib.pyplot as plt

def display_size ():
    # print('What dimensions would you like?')
    YMax = 10 # int(input('Max Y = '))
    YMin = -10 # int(input('Min Y = '))
    XMax = 10 # int(input('Max X = '))
    XMin = -10 # int(input('Min X = '))
    return(YMax,YMin,XMax,XMin)

YMax, YMin, XMax, XMin = display_size()

D = [50,50] # x, y
D.append(D[0]*D[1]) 

MatrixXY = Matrix_Generator(XMin,XMax,YMax,YMin,D)

r = min((XMax-XMin)/(2*(D[0]-1)),(YMax-YMin)/(2*(D[1]-1)))*0.9

k = [r/((m(MatrixXY.x[i],MatrixXY.y[i])**2 + 1)**(1/2)) for i in range(D[2])]

MasterX = []
MasterY = []

for i in range(D[2]):
    MasterX.append([MatrixXY.x[i] - k[i], MatrixXY.x[i] + k[i]])
    MasterY.append([MatrixXY.y[i] - m(MatrixXY.x[i],MatrixXY.y[i])*k[i], MatrixXY.y[i] + m(MatrixXY.x[i],MatrixXY.y[i])*k[i]])

MasterXY = Matrix(MasterX,MasterY)

plt.figure(figsize=(7,7), facecolor='grey')
plt.rcParams.update({'axes.facecolor':'black'})
border = max(len(str(YMax)), len(str(YMin)))/100 + 0.03
plt.subplots_adjust(left=border,bottom=border,right=0.99,top=0.99)




for i in range(D[2]):
    plt.plot(MasterXY.x[i],MasterXY.y[i], color='grey')

if input("Would you like an Euler approximation? (y/n) ").lower() == 'y':
    X,Y = Approximater()
    if max(X) > XMax or min(X) < XMin:
        print("X out of bounds")
    elif max(Y) > YMax or min(Y) < YMin:
        print("Y out of bounds")
    plt.plot(X,Y, color='green', linewidth=2.5)
    print("Final Y is " + str(Y[len(Y) - 1]))
else:
    pass

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

plt.plot([0,0],YBounds, color='blue', linewidth=1) # Y axis
plt.plot(XBounds,[0,0], color='blue', linewidth=1) # X axis

plt.show()