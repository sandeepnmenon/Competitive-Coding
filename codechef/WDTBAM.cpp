#include<bits/stdc++.h>
using namespace std;
int main() {

   long long t;
   scanf("%lld",&t);
   while(t--)
   {
        long long n,cnt=0;
        scanf("%lld",&n);
        char a[1003],b[1003];
        scanf(" %s %s",a,b);
        long long w[n];
        for(int i=0;i<=n;++i)
        {
            scanf("%lld",&w[i]);
            if(i<n and a[i]==b[i])
                cnt++;
        }
        long long ans;
        ans=w[cnt];
        if(n!=cnt)
            for(long long i=0;i<=cnt;++i)
                    ans=max(ans,w[i]);
        printf("%lld\n",ans);

   }
    return 0;
}
