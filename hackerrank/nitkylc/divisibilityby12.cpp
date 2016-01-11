#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long dp[100005][12];
int main() {
    int t;
    string s;
    scanf("%d",&t);
    while(t--   )
    {
        cin>>s;
        long long sum;
        int n=s.length();
        dp[0][0]=1;
        for(int i=1;i<=n;++i)
        {

            for(int j=0;j<12;++j)
            {
                sum=0;
                for(int k=0;k<12;++k)
                    if((k*10+s[i-1]-'0')%12==j)
                        sum+=dp[i-1][k];
                dp[i][j]=sum+dp[i-1][j];
                if(dp[i][j]>=mod)
                    dp[i][j]=dp[i][j]%mod;


            }
        }
        printf("%lld\n",dp[n][0]-1);

    }
    return 0;
}
