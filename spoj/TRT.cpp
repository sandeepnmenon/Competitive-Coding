#include<cstdio>
#include<algorithm>
using namespace std;
int dp[2001][2001];
int solve(int arr[],int n,int i,int j)
{
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int day=n+i-j;
    return dp[i][j]=max(solve(arr,n,i+1,j)+day*arr[i],solve(arr,n,i,j-1)+day*arr[j]);
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            dp[i][j]=-1;
    int ans=solve(a,n,0,n-1);
    printf("%d",ans);

}
