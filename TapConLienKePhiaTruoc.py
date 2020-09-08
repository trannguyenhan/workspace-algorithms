# Y tuong thuat toan 
# Co cac truong hop sau co the xay ra : 
# 1. VD : 1 3 5 7 ( cac so o vi tri cuoi cach nhau hon 1 dv)
# 2. VD : 1 3 6 7, 1 5 6 7 ( cac so o vi tri cuoi lan luot 2,3,.. so cach nhau 1dv)
# Cach lam : dem nguoc tu cuoi lay so cac so cach nhau 1 donvi -> Goi la day cuoi tang dan
# Giam so cuoi cung cua day cuoi tang dan di 1 don vi

# Kiem tra tap con de bai cho co phai la tap con dau tien?
# Tap con dau tien : 1,2,3,... (Tuy vao K)
def isFirstSub(A):
    # Neu phan tu dau tien khac 1 -> sai
    if(A[0] != 1) : 
        return False

    lens = len(A)
    dem = 0
    for x in range(0,lens-1,1):
        if(A[x]+1 == A[x+1]) : 
            dem = dem + 1

    if(dem == lens-1) : 
        return True
    else : 
        return False

# In ra tap con cuoi cung 
def printLastSub(N, K): 
    for x in range(0,K):
        print(N-K+1+x,end=" ")

# In ra tap con bat ki
def printSub(A):
    lens = len(A)
    for x in range(0,lens,1):
        print(A[x],end=" ")
 
def printResult(A, N, K):
    # Neu la tap con dau tien -> tra ve tap con cuoi cung
    if(isFirstSub(A)):
        printLastSub(N,K)
        return
    
    # Neu khong phai la tap con dau tien -> thuc hien thuat toan ban dau da dua ra
    lens = len(A)
    for x in range(lens-1, 0, -1):
        if(A[x-1] + 1 != A[x]): 
            break
    
    ## Giam so cuoi cung cua day cuoi tang dan di 1 don vi
    A[x] = A[x] - 1

    # In ket qua 
    printSub(A)
    print()

# main()
T = int(input())
while(T>0):
    N, K = map(int, input().split())
    tapcon = [int(x) for x in input().split()]
    printResult(tapcon,N,K)
    T = T - 1

