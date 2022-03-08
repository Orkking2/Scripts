Num = int(input('\n'+"What number would you like the Factorial of (n!) n = "))

def Factorial (step):
    if step == 1:
        return(1)
    else:
        return(step*Factorial(step-1))

print('\n'+str(Factorial(Num)))