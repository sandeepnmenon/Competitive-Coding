#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
bool dp[1003][1024];
int a[1003];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int n,k;
    while(t--)
    {
        memset(dp,false,sizeof(dp));
        cin>>n>>k;
        for(int i=0;i<n;++i)
            cin>>a[i];

        for(int i=0;i<n;++i)
            for(int j=0;j<1024;++j)
        {
            if(j==0)
                dp[i][j]=true;
            else if(i==0)
                dp[i][j]=(j==a[i])?true:false;
            else
                dp[i][j]=dp[i-1][j] or dp[i-1][j xor a[i]];
        }
        int ans=0;
        for(int i=0;i<1024;++i)
        {
            if(dp[n-1][i])
                ans=max(ans,k xor i);
        }
        cout<<ans<<endl;


    }

    return 0;
}
