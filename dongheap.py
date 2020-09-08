#Xay dung CTDL heap 
# father - leftChild - rightChild
def father(A, i):
	return int((i-1)/2)

def leftChild(A, i):
	return i*2+1

def rightChild(A, i):
	return i*2+2

#Xay dung tinh chat dong
def maxHeapify(A, i, n):
	left = leftChild(A,i)
	right = rightChild(A,i)

	# i = min(Child(i))
	if((left<n) and (A[left] > A[i])): 
		largest = left
	else:
		largest = i
	
	if((right<n) and (A[right] > A[largest])): 
		largest = right

	if(largest != i):
		(A[largest],A[i]) = (A[i],A[largest])
		maxHeapify(A,largest,n)
	
#Vun dong 
def buildMaxHeap(A, n):
	for i in range(int(n/2),-1,-1):
		maxHeapify(A,i,n)

A = [5,9,6,7,10,5,8]
print(A)
buildMaxHeap(A,7)
print(A)

#Main()
