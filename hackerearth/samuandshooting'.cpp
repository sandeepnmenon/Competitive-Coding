#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
double dp[1005][1005];
double p1,p2;
int main() {

   long long t;
   scanf("%lld",&t);
   while(t--)
   {
        int n,w,a,b,x,y;
        memset(dp,0,sizeof(dp));
        scanf("%d %d %d %d %d %d",&x,&y,&n,&w,&a,&b);
        for(int i=0;i<=n;i++)
			for(int j=0;j<=w;j++)
				dp[i][j]=0;

        p1=0.01*a;
        p2=0.01*b;
        double res1,res2;
        for (int i=0;i<=n;i++)
      		dp[i][0] = 1;
    	for (int i=1;i<=w;i++)
      		dp[0][i] = 0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=w;++j)
                {
                    if(j>x)
                        res1=p1*dp[i-1][j-x] + (1-p1)*dp[i-1][j];
                    else
                        res1=p1*dp[i-1][0] + (1-p1)*dp[i-1][j];
                    if(j>y)
                        res2=p2*dp[i-1][j-y] + (1-p2)*dp[i-1][j];
                    else
                         res2=p2*dp[i-1][0] + (1-p2)*dp[i-1][j];
                    dp[i][j]=max(res1,res2);
                }
        printf("%.6lf\n",dp[n][w]*100);
   }
    return 0;
}
