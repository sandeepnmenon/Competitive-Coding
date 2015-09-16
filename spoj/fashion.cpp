#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    scanf("%lld",&t);
    while(t--)
    {
        int n,rat;
        scanf("%d",&n);
        int men[n],wom[n];
        for(int i=0;i<n;++i)
            scanf("%d",&men[i]);
        for(int i=0;i<n;++i)
            scanf("%d",&wom[i]);
        sort(men,men+n);
        sort(wom,wom+n);
        long long ans=0;
        for(int i=0;i<n;++i)
            ans+=men[i]*wom[i];
        printf("%lld\n",ans);

    }
    return 0;
}
