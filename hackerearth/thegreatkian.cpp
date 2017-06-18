<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long n,x,one=0,two=0,three=0;
    scanf("%lld",&n);
    for(long long i=1;i<=n;++i)
    {
        scanf("%lld",&x);
        if(i%3==0)
            three+=x;
        else if((i+1)%3==0)
            two+=x;
        else
            one+=x;
    }
    printf("%lld %lld %lld",one,two,three);

    return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long n,x,one=0,two=0,three=0;
    scanf("%lld",&n);
    for(long long i=1;i<=n;++i)
    {
        scanf("%lld",&x);
        if(i%3==0)
            three+=x;
        else if((i+1)%3==0)
            two+=x;
        else
            one+=x;
    }
    printf("%lld %lld %lld",one,two,three);

    return 0;
}
>>>>>>> 137199fba6bf1ae89e1bd0436b0ee31d0e6c270b
