Table = open("Kaprekar\Kapraker Table.txt", "w+")
kMax=10000
kSize=4

def main():
    for i in range(1,kMax):
        if i % 1111 != 0:
            k = i
            Steps=1
            while k != 6174:
                k=Update(k,kSize)
                Steps+=1
            Table.write(str(Steps)+', ')
        else:
            Table.write('0, ')

def Update (k,kSize):
    SplitInt=[x for x in str(k)]
    for i in range(kSize-len(SplitInt)):
        SplitInt.append('0')
    SplitInt=[x for x in SplitInt]
    SplitInt.sort()
    A=int("".join(SplitInt))
    D=int("".join(SplitInt[::-1]))
    New=D-A
    return(New)

main()
print('Done')
Table.close()