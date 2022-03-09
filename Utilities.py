def floor (num):
    if round(num) <= num:
        return(round(num))
    else:
        return(round(num)-1)

def ceil (num):
    if round(num) >= num:
        return(round(num))
    else:
        return(round(num)+1)

