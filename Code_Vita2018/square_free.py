from math import sqrt

def isSquareFree(n):
    if n % 2 == 0:
        n = n / 2
    if n % 2 == 0:
        return False
    for i in range(3, int(sqrt(n) + 1)):
        if n % i == 0:
            n = n / i
        if n % i == 0:
            return False
    return True

def ans_val(num):
	count=0
	for i in range(2,num+1):
		if num%i==0:
			if isSquareFree(i):
				count+=1
	return count

value=int(input())
ans=ans_val(value)
print(ans,end='')