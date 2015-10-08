#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long dp[2][1005],up[1005],low[1005];
int main() {

    long long n,m,c,x,maxi=-1;
    scanf("%lld %lld %lld",&n,&m,&c);
    fill(up,up+1005,0);
    fill(low,low+1005,0);
    memset(dp,0,sizeof(dp));
    for(long long i=0;i<n;++i)
    {
        scanf("%lld",&x);
        up[x]++;
        maxi=max(maxi,x);
    }
     for(long long i=0;i<m;++i)
    {
        scanf("%lld",&x);
        low[x]++;
        maxi=max(maxi,x);
    }
    vector<long long> v;
    for(long long i=1;i<=maxi;++i)
        if(up[i]!=0 and low[i]!=0)
            v.push_back(up[i]*low[i]);
    for(long long i=0;i<v.size();++i)
    {
        for(long long j=0;j<=min(i,c);++j)
            if(j==0)
                dp[1][j]=(dp[0][j]+v[i])%mod;
            else
                dp[1][j]=(dp[0][j]+v[i]*dp[0][j-1])%mod;
        for(long long j=0;j<=min(i,c);++j)
            dp[0][j]=dp[1][j]%mod;
    }
    for(long long i=1;i<=c;++i)
        printf("%lld ",dp[0][i]);

    return 0;
}
