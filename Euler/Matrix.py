def floor (num):
    if round(num) <= num:
        return(round(num))
    else:
        return(round(num)-1)

class Matrix:
    def __init__(self,XComponent,YComponent):
        self.x = XComponent
        self.y = YComponent

def Matrix_Generator (XMax,XMin,YMax,YMin,D):
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

    for x in range(1,D[2]+1):
        XList.append(MatrixX[(x - 1) % D[0]])
        YList.append(MatrixY[floor((x - 1)/D[0])])

    MatrixXY = Matrix(XList,YList)

    return(MatrixXY)