#include<bits/stdc++.h>
using namespace std;
long long solve(long long x,long long y,long long m)
{
        long long minm=min(x,y);
        long long n;
        if(m>=minm)
            {
                x-=minm;
                y-=minm;
                return x+y;
            }
        else if(m*(m+1)/2<=minm)
            {
                x-=(m*(m+1)/2);
                y-=(m*(m+1)/2);
                return x+y;
            }
        else
        {
            n=floor((-1+sqrt(1-4*(2*minm-m*m-m)))/2);
            x=x-(m*(m+1)/2)+(n*(n+1)/2);
            y=y-(m*(m+1)/2)+(n*(n+1)/2);
            m=n;
            return solve(x,y,m);
        }
}
int main()
{
    long long t,x,y,m,minm;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&x,&y,&m);
        long long ans=solve(x,y,m);
        printf("%lld\n",ans);

    }
}
