#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    long long t,n,x,ans,a,b,c;
    double sl,in;
    scanf("%lld",&t);
    pair<double,double> p;
    while(t--)
    {
        map<double,set<double> >m;

        scanf("%lld",&n);
        for(long long i=0;i<n;++i)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            if(b==0)
            {
                sl=mod;
                in=(double)c/a;
            }
            else
            {
                sl=(double)a/b;
                in=(double)c/b;
            }
            (m[sl]).insert(in);
        }

        map<double,set<double> > ::iterator it=m.begin();
        ans=-1;
        while(it!=m.end())
        {
            if(ans<(it->second).size())
                ans=(it->second).size();
            it++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
