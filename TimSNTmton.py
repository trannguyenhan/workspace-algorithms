import math

def kiemtraSNT(a):
	if(a<=1):
		return False
	else:
		run = int(math.sqrt(a))
		for i in range(2,run+1) : 
			if(a%i == 0) : 
				return False
	return True	

n1, n2 = map(int, input().split())


for i in range(n1,n2+1) : 
	if(kiemtraSNT(i)) : 
		print(i)
