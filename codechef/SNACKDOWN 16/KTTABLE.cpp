#include<bits/stdc++.h>
using namespace std;
long long a[10004];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf(" %lld",&a[i]);
        int ans=0;
        long long b;
        a[0]=0;
        for(int i=1;i<=n;++i)
        {
            scanf(" %lld",&b);
            if(a[i]-a[i-1]>=b)
                ans++;
        }
        printf("%d\n",ans);
    }
}
