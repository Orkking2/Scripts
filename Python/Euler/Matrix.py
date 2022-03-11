def floor (num):
    if round(num) <= num:
        return(round(num))
    else:
        return(round(num)-1)

class Matrix:
    def __init__(self):
        pass
    def Point(self,YComponent,XComponent):
        self.x = XComponent
        self.y = YComponent
    def Generate (self,XMax,XMin,YMax,YMin,D):
        XDist = XMax - XMin
        YDist = YMax - YMin

        D = [D[0],D[1],D[0]*D[1]]

        XSpacing = XDist/(D[0]-1)
        YSpacing = YDist/(D[1]-1)

        MatrixX = []
        MatrixY = []

        for i in range(D[0]):
            MatrixX.append(i*XSpacing + XMin)
        for i in range(D[1]):
            MatrixY.append(i*YSpacing + YMin)

        XList = []
        YList = []

        for i in range(D[2]):
            XList.append(MatrixX[i % D[0]])
            YList.append(MatrixY[floor(i/D[0])])

        Matrix.Point(self,XList,YList)