#include<bits/stdc++.h>
using namespace std;
long long val[510],siz[510];
void knapsack(long long n,long long s)
{
    long long kp[s+1];
    fill(kp,kp+s+1,LONG_LONG_MAX);
    for(long long i=1;i<=s;++i)
        for(long long j=0;j<n;++j)
            {
                if(siz[j]==i)
                    kp[i]=min(kp[i],val[j]);
                else if(i>siz[j] and kp[i-siz[j]]!=LONG_LONG_MAX)
                    kp[i]=min(kp[i],val[j]+kp[i-siz[j]]);
            }



    if(kp[s]!=LONG_LONG_MAX)
    printf("The minimum amount of money in the piggy-bank is %lld.\n", kp[s]);
     else
        printf("This is impossible.\n");

}

int main() {

   long long t;
   scanf("%lld",&t);
   while(t--)
   {
       long long e,f;
       scanf("%lld %lld",&e,&f);
       long long n;
       scanf("%lld",&n);
       for(long long i=0;i<n;++i)
        scanf("%lld %lld",&val[i],&siz[i]);
        knapsack(n,f-e);

   }
    return 0;
}
