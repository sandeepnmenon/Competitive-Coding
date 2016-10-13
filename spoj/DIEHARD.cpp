#include<bits/stdc++.h>
using namespace std;
int ans,dp[3000][3000];
int solve(int h,int a,int ans,char ch)
{
    if(h<=0 or a<=0)
        return ans;
    if(dp[h][a]!=-1)
        return dp[h][a];
    ans++;
    if(ch=='a')
        dp[h][a]=max(solve(h-5,a-10,ans,'w'),solve(h-20,a+5,ans,'f'));
    else if(ch=='w')
        dp[h][a]=solve(h+3,a+2,ans,'a');
    else
        dp[h][a]=solve(h+3,a+2,ans,'a');

    return dp[h][a];


}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int h,a;
        scanf("%d %d",&h,&a);
        for(int i=0;i<3000;++i)
            for(int j=0;j<3000;++j)
                dp[i][j]=-1;
        ans=1;
        h+=3;
        a+=2;
        ans=solve(h,a,ans,'a');
        printf("%d\n",ans-1);

    }
    return 0;
}
