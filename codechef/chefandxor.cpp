#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n==1)
            printf("2");
        else
        {
            n++;
            if(!(n&(n-1)))
            {
            n--;
            printf("%lld",n>>1);
            }
            else
                printf("-1");
        }
        printf("\n");
    }
}
