#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m;
    scanf("%d",&t);
    string s;
    while(t--)
    {
        scanf("%d",&n);
        int ca,cb,ta=INT_MAX,tb=INT_MAX;
        for(int i=0;i<n;++i)
        {
            cin>>s;
            ca=cb=0;
            for(int j=0;j<s.length();++j)
                if(s[j]=='a')
                    ca++;
                else
                    cb++;

            ta=min(ta,ca);
            tb=min(tb,cb);


        }
        printf("%d\n",min(ta,tb));

    }
}
