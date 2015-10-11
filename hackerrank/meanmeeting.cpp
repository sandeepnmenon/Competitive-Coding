#include<bits/stdc++.h>
using namespace std;
long long bit[100003],a[100003],n;
void update(long long idx,long long val)
{
    while(idx<=n)
    {
        bit[idx]+=val;
        idx+=(idx&-idx);
    }
}
long long query(long long idx)
{
    long long sum=0;
    while(idx>0)
    {
        sum+=bit[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
int main()
{
    scanf("%lld",&n);
    for(long long i=0;i<n;++i)
    {
        scanf("%lld",&a[i]);
        update(i+1,a[i]);
    }
    long long q,l,r;
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld %lld",&l,&r);
        n=query(r)-query(l-1);
        printf("%lf\n",(double)n/(r-l+1));
    }


    return 0;
}
