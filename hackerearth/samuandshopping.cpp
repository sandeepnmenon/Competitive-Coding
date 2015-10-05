#include<bits/stdc++.h>
using namespace std;
int dp[100005][3],item[100005][3];
int main() {

   long long t;
   scanf("%lld",&t);
   while(t--)
   {
        long long n;
        scanf("%lld",&n);
        for(long long i=0;i<n;++i)
            for(int j=0;j<3;++j)
                scanf("%d",&item[i][j]);
        dp[0][0]=item[0][0];
        dp[0][1]=item[0][1];
        dp[0][2]=item[0][2];
        for(long long i=1;i<n;++i)
        {
            dp[i][0]=min(dp[i-1][1],dp[i-1][2])+item[i][0];
            dp[i][1]=min(dp[i-1][0],dp[i-1][2])+item[i][1];
            dp[i][2]=min(dp[i-1][1],dp[i-1][0])+item[i][2];
        }
        printf("%d\n",min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2])));


   }
    return 0;
}
