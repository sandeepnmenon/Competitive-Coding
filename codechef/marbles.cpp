#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long comb(int n,int r)
{
    if(r>n/2)
        r=n-r;
    long long num=1;
    for(int i=1;i<=r;++i)
    {
        num*=(n-i+1);
        num=num/i;
    }
    return num;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,r;
        scanf("%d %d",&n,&r);
        printf("%lld\n",(long long)comb(n-1,r-1));
    }
    return 0;

}
