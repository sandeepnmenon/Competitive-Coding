#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
	long long n,q,maxi,mini;
	scanf(" %lld %lld",&n,&q);
	maxi=-1;
	mini=LONG_LONG_MAX;
	long long t;
	for(long long i=0;i<n;++i)
	{
		scanf(" %lld",&a[i]);
		maxi=max(maxi,a[i]);
		mini=min(mini,a[i]);
	}
	while(q--)
	{
		scanf(" %lld",&t);
		if(t>=mini and t<=maxi)
			printf("Yes\n");
		else
			printf("No\n");
	}



	return 0;
}