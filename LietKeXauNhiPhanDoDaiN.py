N = 0
list = []

# In ket qua
def printResult():
    for x in range(0,N):
        print(list[x],end="")
    print()

# Quay lui
def TRY(a):
    global N
    global list

    for x in range(0,2):
        list[a-1] = x
        if a == N:
            printResult()   
        else:
            TRY(a+1)
    

#main()
N = int(input())

#Khoi tao khong gian cho list
list = [0 for i in range(0,N)]

TRY(1)
