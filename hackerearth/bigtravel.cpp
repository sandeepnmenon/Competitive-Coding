#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long x[200005],y[200005];
int main()
{
    long long n;
    scanf("%lld",&n);
    for(long long i=0;i<n;++i)
        scanf("%lld %lld",&x[i],&y[i]);
    sort(x,x+n);
    sort(y,y+n);
    long long ans=0;
    for(long long i=0;i<n;++i)
        ans=(ans+(x[i]+y[i])*(i-(n-1-i)) +mod )%mod;
    printf("%lld",ans%mod);
    return 0;

}
