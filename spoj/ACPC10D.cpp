#include<bits/stdc++.h>
using namespace std;
long long dp[1000003][3],graph[1000003][3],n;
int main()
{
    long long k=1;
    while(1)
    {
        scanf("%lld",&n);
        if(n==0)
            break;
        for(long long i=0;i<n;++i)
            for(long long j=0;j<3;++j)
               {
                scanf("%lld",&graph[i][j]);
                dp[i][j]=0;
               }

        dp[0][1]=graph[0][1];
        dp[0][2]=graph[0][1]+graph[0][2];
        dp[1][0]=graph[0][1]+graph[1][0];
        dp[1][1]=graph[1][1]+min(dp[1][0],min(dp[0][1],dp[0][2]));
        dp[1][2]=graph[1][2]+min(dp[0][2],min(dp[0][1],dp[1][1]));
        for(long long i=2;i<n;++i)
        	for(long long j=0;j<3;++j)
        		if(j==0)
        			dp[i][j]=graph[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
        		else if(j==1)
        			dp[i][j]=graph[i][j]+min(dp[i][j-1],min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1])));
        		else if(j==2)
        			dp[i][j]=graph[i][j]+min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));


        printf("%lld. %lld\n",k,dp[n-1][1]);
        k++;

    }
    return 0;
}
