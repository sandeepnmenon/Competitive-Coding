#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    long n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;++i)
        {
            cin>>a[i]>>b[i];
        }
        long num=n;
        for(long i=0;i<n;++i)
        {
            for(long j=0;j<n;++j)
            {
                if(i!=j&&((a[i]>=a[j]&&a[i]<=b[j])||(b[i]>=a[j]&&b[i]<=b[j])))
                    num--;

            }
        }
        cout<<num<<endl;
    }

}
