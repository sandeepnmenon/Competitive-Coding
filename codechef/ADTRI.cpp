#include<bits/stdc++.h>
#define mod 1000007

using namespace std;
bool pyth[5000005];
void init()
{
    fill(pyth,pyth+5000005,false);
    long long c,p;
    for(long long i=1;i<=2500;++i)
        for(long long j=i+1;i*i+j*j<=5000005;++j)
    {
            c=i*i+j*j;
            for(long long x=c;x<5000005;x+=c)
                pyth[x]=true;
    }
}
int main() {

    init();
    long long t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(pyth[n])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
