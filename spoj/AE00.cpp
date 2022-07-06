#include<cstdio>
#include<bits/stdc++.h>
int main()
{
    long long n,div,sq;
    scanf("%lld",&n);
    long long dp[n+1];
    dp[1]=1;
    for(long long i=2;i<=n;++i)
    {
        dp[i]=dp[i-1]+1
        ;
        div=0;
        sq=floor(sqrt(i));
        for(long long j=2;j<=sq;++j)
            if(i%j==0)
                div++;
        dp[i]+=div;

    }
    printf("%lld",dp[n]);
  return 0;
}
