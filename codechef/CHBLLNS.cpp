#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n;
    long long r,g,b,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&r,&g,&b);
        scanf("%lld",&k);
        long long ans=0;
        ans=3*(k-1)+1;
        k--;
        if(k>r)
            ans-=(k-r);
        if(k>g)
            ans-=(k-g);
        if(k>b)
            ans-=(k-b);

        printf("%lld\n",ans);
    }
    return 0;
}
