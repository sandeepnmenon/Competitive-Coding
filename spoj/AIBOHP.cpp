#include<bits/stdc++.h>
using namespace std;
int dp[6103][6103];
int lcs_len(string a,string b,int dp[][6103])
{
    int len=a.length();
    for(int i=0;i<=len;++i)
        for(int j=0;j<=len;++j)
    {
        if(i==0 or j==0)
            dp[i][j]=0;
        else
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    }
    return dp[len][len];
}
int main() {

   long long t;
   scanf("%lld",&t);
   while(t--)
   {
       string s;
       cin>>s;
       int len=s.length();
        string rev=string(s.rbegin(),s.rend());
        int sub=lcs_len(s,rev,dp);
        printf("%d\n",len-sub);
   }
}
