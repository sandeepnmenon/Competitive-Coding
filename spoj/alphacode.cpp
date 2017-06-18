#include<bits/stdc++.h>
using namespace std;
long long dp[5001];
int main()
{
    string s;
    while(1)
    {
        cin>>s;
        if(s[0]=='0')
            break;
        int len=s.length();
        dp[0]=dp[1]=1;
        for(int i=2;i<=len;++i)
        {
            dp[i]=0;
            int x=s[i-2]-48, y=s[i-1]-48;
            if(x==1 or (x==2 and y<=6))
                dp[i]+=dp[i-2];
            if(y!=0)
                dp[i]+=dp[i-1];
        }
        printf("%lld\n",dp[len]);

    }
}
