#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int t;
    unsigned long long n,prod=1,num,mul=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<=4)
        {

        cout<<n<<endl;
        continue;
        }
        num=sqrt(n);
        prod=pow(num,n/num);
        if(n%num!=0)
            prod=prod*(n%num);
        mul=pow(num+1,n/(num+1));
        mul=mul*(n%(num+1));
        if(prod>mul)
            if(prod>1000000007)
            cout<<prod%1000000007<<endl;
            else
                cout<<prod<<endl;
        else
            if(mul>1000000007)
            cout<<mul%1000000007<<endl;
            else
                cout<<mul<<endl;
    }
}
