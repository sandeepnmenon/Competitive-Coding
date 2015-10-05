#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long dp[1000005];
void init()
{
    dp[1]=1;
    dp[2]=2;
    for(long long i=3;i<=1000003;++i)
        {
            dp[i]=dp[i-1]+(i-1)*dp[i-2];
            if(dp[i]>=mod)
                dp[i]=dp[i]%mod;
        }
}
int main() {

   long long t;
   scanf("%lld",&t);
init();
   while(t--)
   {
        long long n;
        scanf("%lld",&n);
        printf("%lld\n",dp[n]);
   }
    return 0;
}
