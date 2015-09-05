#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    long long n;
    while(t--)
    {
        scanf("%lld",&n);
        if(n%2==0)
            printf("ALICE\n");
        else
            printf("BOB\n");
    }
    return 0;
}
