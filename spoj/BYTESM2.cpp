#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int mat[105][105],dp[105][105];
int main()
{
    int h,w,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&h,&w);
        int ans=0;
        for(int i=0;i<=h+1;++i)
            for(int j=0;j<=w+1;++j)
            {
                dp[i][j]=0;
                if(i==0 or j==0 or i==h+1 or j==w+1)
                    {
                        mat[i][j]=0;
                        continue;
                    }
                scanf(" %d",&mat[i][j]);
                if(i==1)
                    dp[i][j]=mat[i][j];
            }
        for(int i=2;i<=h;++i)
            for(int j=1;j<=w;++j)
                dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]))+mat[i][j];
        for(int i=1;i<=w;++i)
            ans=max(ans,dp[h][i]);
        printf("%d\n",ans);





    }
    return 0;
}
