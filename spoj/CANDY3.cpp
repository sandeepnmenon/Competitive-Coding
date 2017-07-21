#include<cstdio>
#include<bits/stdc++.h>
int main()
{
    int t;
    long long n,sum,a;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%lld",&n);
        for(long long i=0;i<n;++i)
        {
            scanf("%lld",&a);
            sum=(sum+a)%n;
        }
        sum=sum%n;
        if(sum==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
  return 0;
}
