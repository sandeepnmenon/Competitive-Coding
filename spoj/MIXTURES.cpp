#include<bits/stdc++.h>
using namespace std;
int rsum(int a[],int i,int j)
{
    int sum=0;
    for(int k=i;k<=j;++k)
        {sum+=a[k];
        if(sum>=100)
            sum=sum%100;}
    return sum%100;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int a[n];
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        int dp[n+1][n+1];
        for(int i=1;i<=n;++i)
            dp[i][i]=0;
        for(int l=2;l<=n;++l)
            for(int i=1;i<=n-l+1;++i)
        {
            int j=i+l-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;++k)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+rsum(a,i,k)*rsum(a,k+1,j));

        }
        printf("%d\n",dp[1][n]);

    }
  return 0;
}
