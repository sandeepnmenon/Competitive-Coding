#include<bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string a;
    int t;
    scanf("%d",&t);
    while(t--)
        {
        cin>>a;
        sort(a.begin(),a.end());
        long long x,sm,la;
        bool flag=false;
        do
            {
                x=stoi(a);
               // printf("%lld\n",x);
                if(x%8==0)
                    {
                    if(!flag)
                    {  sm=x;  flag=true;}
                    la=x;
                }
        }while(next_permutation(a.begin(),a.end()));
        if(!flag)
            printf("-1\n");
        else
            printf("%lld %lld\n",sm,la);
    }

    return 0;
}
