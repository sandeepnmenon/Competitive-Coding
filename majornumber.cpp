#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    unsigned long t,n,i;
    bool flag;
    scanf("%lu",&t);
    while(t--)
    {
        flag=0;
        scanf("%lu",&n);
        unsigned long long a[n];
        for(i=0;i<n;++i)
            scanf("%llu",&a[i]);
        for(i=0;i<n;++i)
            if(count(a,a+n,a[i])>n/2)
        {
            flag=1;
            break;
        }
        if(flag)
            printf("%llu\n",a[i]);
        else
            printf("NO MAJOR\n");
    }
}
