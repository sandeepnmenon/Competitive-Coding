#include<bits/stdc++.h>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t,l,q;
    long long n,g,head;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&g);
        for(long long i=0;i<g;++i)
        {
            scanf("%d %lld %d",&l,&n,&q);
            if(!(n&1))
            {
                printf("%lld\n",n/2);
            }
            else
            {
                if(l==1)
                    head=n/2;
                else
                    head=n/2+1;
                if(q==1)
                    printf("%lld\n",head);
                else
                    printf("%lld\n",n-head);
            }



        }
    }
    return 0;
}
