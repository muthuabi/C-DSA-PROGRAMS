from math import ceil
def small_div(n):
	for i in range(2,ceil(n/2)+1):
		if(n%i==0):
			return i
	return n
n=int(input("Enter the Number:"))
print(small_div(n))