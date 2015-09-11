#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long i,k,s;
    long double ai,bi;
    scanf(" %lld %lld %lld",&i,&k,&s);
    scanf(" %llf %llf",&ai,&bi);
    printf("%lld %lld %lld %llf %llf\n",i,k,s,ai,bi);
    long double res;
    if(i==k)
        res=(ai+bi)/pow(2,s);
    else if(i<k)
        {if((k-i)%2==0)
            res=(ai+bi)/pow(2,2*k-2*i+s);
        else
            res=(sqrt(2)*ai+sqrt(6)*bi)/pow(2,2*k-2*i-s+1);}
    else
        {if((i-k)%2==0)
            res=(ai+bi)*pow(2,2*i-2*k-s);
        else
            res=(sqrt(2)*ai+sqrt(6)*bi)*pow(2,2*i-2*k-s-1);}
    printf("%llf",res);
    return 0;
}
