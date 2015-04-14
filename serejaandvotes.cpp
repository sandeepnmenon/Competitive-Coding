#include<iostream>
using namespace std;

int main()
{
    int t;

    long n,sum=0,num=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int b[n];
        sum=num=0;
        for(int i=0;i<n;++i)
        {
            cin>>b[i];
            sum+=b[i];
            if(b[i]!=0)
                num++;
        }
        if(sum>=100&&((sum-100)<=num-1))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
