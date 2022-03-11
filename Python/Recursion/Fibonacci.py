Num = int(input('\n'+"How many steps would you like to take the Fibonnaci sequence to? "))

def Fibonacci (step):
    if step == 1:
        k = 1
    elif step == 2:
        k = 1
    else:
        k = Fibonacci(step-1) + Fibonacci(step-2)
    return(k)

print('\n'+str(Fibonacci(Num)))