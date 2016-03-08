#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],prod[100005];
int main()
{
    long long t,n,ans;
    long long k;
    scanf("%lld",&t);
    while(t--)
    {
        ans=0;
        scanf("%lld %lld",&n,&k);
        for(long long i=0;i<n;++i)
            scanf("%lld",&a[i]);
        for(long long i=0;i<n;++i){
            scanf("%lld",&b[i]);
            ans+=a[i]*b[i];
        }
        long long x=0,p=LONG_LONG_MIN,dif;
        for(long long i=0;i<n;++i)
        {
            if(a[i]>=0 and b[i]>=0)
            {
                dif=k*b[i];
            }
            else if(a[i]<=0 and b[i]<=0)
            {
                dif=-k*b[i];
            }
            else if(a[i]>=0 and b[i]<=0)
            {
                dif=-k*b[i];
            }
            else if(a[i]<=0 and b[i]>=0)
            {
                dif=k*b[i];
            }
            p=max(dif,p);
        }
        ans+=p;
        printf("%lld\n",ans);
    }
    return 0;
}
