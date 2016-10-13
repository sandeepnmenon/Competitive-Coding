from fractions import gcd
t=input()

dp=[]
def lcm(a,b):
	return (a*b)/gcd(a,b)
	
def init():
	dp.append(0)
	dp.append(1)
	dp.append(2)
	for i in range (3,10002):
		if(dp[i-1]%i==0):
			dp.append(dp[i-1])
		else:
			dp.append(lcm(dp[i-1],i))

init()			
while t>0:
	n=input()
	print dp[n]%1000000007
	t-=1
	