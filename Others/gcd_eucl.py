def gcd2(x,y):
	gcd=min=x if x<y else y
	for i in range(min,0,-1): #for i in range(min,1,-1):
		print("Hello")
		if x%i==0 and y%i==0:
			gcd=i
			break
	return gcd
def gcd1(x,y):
	if(x==0 or x<y): #Failed
		return y
	else:
		return gcd1(x%y,y)
x=int(input("Enter x:"))
y=int(input("Enter y:"))
while(y==0):
	y=int(input("Enter y(again):"))
print(gcd2(x,y))