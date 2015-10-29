#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    scanf("%lld",&n);
    long long a[n];
    long long sum[n];
    for(long long i=0;i<n;++i){
        scanf("%lld",&a[i]);
        sum[i]=a[i]*a[i];}
    long long ac=0,ob=0,rt=0,*k=NULL,x,ki;
    long long *p=NULL,pi;
    for(long long i=0;i<n-2;++i)
        for(long long j=i+1;j<n-1;++j)
        {
            if(a[i]+a[j]>a[n-1])
                k=&a[n-1];
            else
              {
                  k=lower_bound(a+j,a+n,a[i]+a[j]);
                  k--;
              }
            if(sum[i]+sum[j]>sum[n-1])
                p=&sum[n-1];
            else
            {
                p=lower_bound(sum+j,sum+n,sum[i]+sum[j]);
                if(*p==sum[i]+sum[j])
                    {rt++; ac--;}
                else
                    p--;
            }
            ki=k-&a[0];
            pi=p-&sum[0];
            //printf("%d %d %d %d\n",a[ki],a[pi],a[i],a[j]);
            //printf("%d\n",ac);
            ac+=(pi-j);
            ob+=(ki-pi);
            //printf("%d\n",ac);
        }
           // printf("%d %d %d\n",*k,a[i],a[j]);

    printf("%lld %lld %lld",ac,rt,ob);
    return 0;
}
