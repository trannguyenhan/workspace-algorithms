def tempFunc(arr,k):
    pass

#print special number
def specialNumber(arr, k):
    arr.sort()
    lens = len(arr)

    if k <= lens:
        return arr[k-1]
    else : 
        return tempFunc(arr,k)

#main()
#input array A and integer k
k = int(input())
A = [int(x) for x in input().split()]

print(specialNumber(A,k))
