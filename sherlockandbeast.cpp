#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--)
        {
        long n;
        cin>>n;
        long num=n;

        while(num%3!=0)
            num--;
        while((((n-num)%5!=0||num%3!=0)&&num!=0))
            num--;
        if(num==0)
        {
            if(num%5==0)
            {
            for(long i=0;i<n;++i)
                cout<<"3";
            cout<<endl;
            continue;
        }
            cout<<"-1"<<endl;
            continue;
        }
        for(long i=0;i<n;++i)
            if(i<num)
                cout<<"5";
            else
                cout<<"3";
            cout<<endl;
        }

    return 0;
}
