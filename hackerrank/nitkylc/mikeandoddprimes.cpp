#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isprime(long long n)
    {
    if(n==1)
        return false;
    for(int i=2;i<=sqrt(n);++i)
        if(n%i==0)
            return false;
     return true;
}
bool isodd(long long n)
    {
    if(n%2==1)
        return true;
    return false;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    scanf("%d",&t);
    long long n;
    while(t--)
        {
            scanf("%lld",&n);

            if(isprime(n)==isodd(n))
                printf("Yes\n");
            else
                printf("No\n");
    }
    return 0;
}
