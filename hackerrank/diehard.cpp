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
    long a,b,c,res;
    while(t--)
        {
        cin>>a>>b>>c;
        if(a!=c)
            if((a<c&&b<c)||a==b)
                {
                    cout<<"-1"<<endl;
                    continue;
                }
        res=0;
        while(a!=c&&b!=c)
            {
            if(a>c)
                {
                a=a-b;
            }
            else if(b>c)
                {
                b=b-a;
            }
            res++;
        }
       cout<<res+1<<endl;
    }
    return 0;
}
