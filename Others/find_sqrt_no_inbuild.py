from math import sqrt as s
def find_sqrt(n): #INACCURATE
	if n<2:
		return n
	low=float(1)
	high=float(n)
	while low<=high:
		mid=(low+high)/2
		if n==(mid*mid):
			return mid
		elif n<(mid*mid):
			high=mid-1
		else:
			low=mid+1
	return high

n=float(input("Enter the Number:"))
print(find_sqrt(n))
print(s(n))