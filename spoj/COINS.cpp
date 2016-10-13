#include<bits/stdc++.h>
using namespace std;
map<long long,long long> dp;
long long coin(long long n)
{
    if(n<12)
        return n;
    if(dp.find(n)!=dp.end())
        return dp[n];
    dp[n]=coin(n/2)+coin(n/3)+coin(n/4);
    return dp[n];

}
int main()
{
    long long n;
    while(scanf("%lld",&n)==1)
    {
        dp.clear();
        n=coin(n);
        printf("%lld\n",n);

    }
  return 0;
}
