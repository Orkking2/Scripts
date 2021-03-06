def questions ():
    X = [int(input("Start X: "))] ## Initial X -> inc'd X
    Y = [int(input("Start Y: "))] ## Initial Y -> inc'd Y
    TargetX = int(input("Target X: "))
    return(X,Y,TargetX)

def m (x,y):
    k = x**2 + y**2 -2*x*y - 3
    return(k)
    
def Choose (TargetX,X):
    NHChoise = input("N/H: ")
    if NHChoise.lower() == 'n':
        N = int(input("N: "))
        if N > 1000000:
            print("N > 1 million, reset to 1000000")
            N = 1000000
        H = (TargetX-X)/N
        return(N,H)
    elif NHChoise.lower() == 'h':
        H = int(input("H: "))
        N = (TargetX-X)/H
        if N > 1000000:
            print("N > million, reset to 1000000")
            N = 1000000
            H = (TargetX-X)/N
        return(N,H)
    else:
        print("\n"+"Print please pick N or H"+"\n")
        Choose()
        return(N,H)

def Approximater():
    X,Y,TargetX = questions()
    N,H = Choose(TargetX,X[0])
    K = []
    if abs(X[0]-TargetX+H)>abs(X[0]-TargetX):
        print("DIVERGENT")
    else:
        for i in range(N):
            K.append(m(X[i],Y[i])*H)
            X.append(X[i] + H)
            Y.append(Y[i] + K[i])
        return(X,Y)