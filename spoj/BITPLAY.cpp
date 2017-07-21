#include<bits/stdc++.h>
#define mod 1000007

using namespace std;
long long countSetBits(long long n)
{
    long long cont = 0;
    while (n)
    {
      cont+=n&1;
      n>>=1;
    }
    return cont;
}
int main() {

    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,k;
    scanf("%lld %lld",&n,&k);
        n--;
        k=countSetBits(n)-k;
        long long p=2;
        while(k>0 and p<=n)
            {
                if(p&n)
                {
                    n^=p;
                    k--;
                }
                p<<=1;
            }
        if(k>0)
            n=-1;
        printf("%lld\n",n);

    }
    return 0;
}
