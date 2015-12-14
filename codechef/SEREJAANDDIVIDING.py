t=raw_input()
t=int(t);
def c7(num):
	if num==0:
		return 0
	ans=""
	while num>0:
		q=num/7
		r=num%7
		ans=ans+str(r)
		num=q
	return ans[::-1]
	
for i in xrange(t):
	a=raw_input()
	b=raw_input()
	l=raw_input()
	a=int(a,7)
	b=int(b,7)
	l=int(l)
	l=7**l
	ans=(a/b)%l
	s=c7(ans)
	print s
	