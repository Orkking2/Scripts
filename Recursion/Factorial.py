def main (step):
    if step == 1:
        return(1)
    else:
        return(step*main(step-1))

print(main(10))