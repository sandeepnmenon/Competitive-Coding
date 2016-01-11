#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main() {
    long long t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        long long ans=0;
        n-=2;
        if(n%2==0)
            ans=(n*n)/4;
        else
            ans=(n/2)*(n/2+1);
        printf("%lld\n",ans);
    }
    return 0;
}
