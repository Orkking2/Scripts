def questions ():
    X = int(input("Start X: ")) ## Initial X -> inc'd X
    Y = int(input("Start Y: ")) ## Initial Y -> inc'd Y
    TargetX = int(input("Target X: "))
    return(X,Y,TargetX)

## k = dy/dx
def m (x,y):
    k = y
    return(k)

def Choose (TargetX,X):
    NHChoise = input("N/H: ")
    if NHChoise.lower() == 'n':
        N = int(input("N: "))
        H = (TargetX-X)/N
        return(N,H)
    elif NHChoise.lower() == 'h':
        H = int(input("H: "))
        N = (TargetX-X)/H
        return(N,H)
    else:
        print("\n"+"Print please pick N or H"+"\n")
        Choose()
        return(N,H)

def Approximater():
    X,Y,TargetX = questions()
    N,H = Choose(TargetX,X)
    if abs(X-TargetX+H)>abs(X-TargetX):
        print("DIVERGENT")
    else:
        for i in range(1,N+1):
            K = m(X,Y)*H
            X = X + H
            Y = Y + K
        print(Y)


Approximater()