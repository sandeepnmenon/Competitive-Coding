#include<iostream>
using namespace std;
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        long long n,k,profit;
        cin>>n>>k;
        long long a[n],b[n];
        for(long long i=0;i<n;++i)
            cin>>a[i];
        for(long long i=0;i<n;++i)
        {
            cin>>b[i];
            if(i==0)
            {
                profit=(k/a[i])*b[i];
                continue;
            }
            if(profit<((k/a[i])*b[i]))
               profit=(k/a[i])*b[i];
        }
        cout<<profit<<endl;

    }
    return 0;
}
