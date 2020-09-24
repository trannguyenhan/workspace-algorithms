def secondMax(arr):
    arrTemp = sorted(arr)
    secondElement = arrTemp[len(arr)-2]

    for x in range(0,len(arr)):
        if secondElement == arr[x]:
            print(x+1)
            break
        

arr = [int(item) for item in input().split()]
secondMax(arr)
