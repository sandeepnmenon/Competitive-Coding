#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b,ans=0;
        scanf("%lld %lld",&a,&b);
        if(a<=b)
        {

            if(b%a==0)
                ans=log2(b/a);
            else
            {
                while((a & (a-1)))
                {
                    a=a/2;
                    ans++;
                }
                if(a>b)
                    swap(a,b);
                ans+=log2(b/a);
            }

        }
        else
        {
            while((a & (a-1)))
                {
                    a=a/2;
                    ans++;
                }
                if(a>b)
                    swap(a,b);
              ans+=log2(b/a);
        }
        printf("%lld\n",ans);

    }
    return 0;

}
