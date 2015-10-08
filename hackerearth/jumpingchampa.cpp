#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
int main()
{
    int t,n,q;
    long long a;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;++i)
        {
            scanf("%lld",&a);
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        long long ans=0;
        for(int i=n-1;i>0;--i)
            ans+=(q*(v[i]-v[i-1]));
        printf("%lld\n",ans);
    }
    return 0;

}
