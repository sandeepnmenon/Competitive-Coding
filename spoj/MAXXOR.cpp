#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long l,r,x;
    scanf("%lld %lld",&l,&r);
    x=l xor r;
    long long ans=pow(2,floor(log(x)/log(2))+1);
    printf("%lld",ans-1);
}
