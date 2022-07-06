#include<bits/stdc++.h>
#define mod 1000007
using namespace std;
int main() {

    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,ans=0;
        scanf("%lld",&n);
        if(n==1)
            printf("2\n");
        else
        {

            ans=((n*(3*n+1)/2)+mod)%mod;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
