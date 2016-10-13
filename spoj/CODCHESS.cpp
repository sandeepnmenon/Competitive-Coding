#include<bits/stdc++.h>
#define mod 1000007

using namespace std;

int main() {

    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        if(n&1)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}
