#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long dp[100003];
int main()
{
    int t;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        long long len=s.length();
        int ch[26]={0};
        dp[0]=1;
        for(long long i=1;i<=len;++i)
        {
            dp[i]=2*dp[i-1];
            if(ch[s[i-1]-'A']!=0)
                dp[i]=dp[i]-dp[ch[s[i-1]-'A']-1]+mod;

            dp[i]=dp[i]%mod;
            ch[s[i-1]-'A']=i;
        }
        printf("%lld\n",dp[len]);

    }
    return 0;
}
