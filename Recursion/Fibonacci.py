steps = 100

def main (step):
    if step == 1:
        k = 1
    elif step == 2:
        k = 1
    else:
        k = main(step-1) + main(step-2)
    return(k)

print(main(steps))