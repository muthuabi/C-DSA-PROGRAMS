from math import ceil
def isPrime(n):
	for i in range(2,ceil(n/2)+1):
		if n%i==0:
			return False
	return True
m=int(input("Enter the start:"))
n=int(input("Enter the End:"))
for i in range(m,n+1):
	if(i==1):
		print(i," is Neither Prime Nor Composite")
		continue
	if(isPrime(i)):
		print(i)