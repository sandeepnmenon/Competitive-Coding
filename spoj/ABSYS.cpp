#include <bits/stdc++.h>
using namespace std;
string itos(long long n)
    {
        string s="";
        while(n) s=char(n%10+'0') + s,n/=10;
        return s;
    }
long long stoi(string s)
    {
        long long tmp=0;
        for(long long i=0;i<s.size();i++)
        {
            if(!isdigit(s[i]))
                return -1;

            tmp=tmp*10+(s[i]-'0');
        }
        return tmp;
    }
int main()
{
    long long t;
    scanf("%lld",&t);
    string a,b,c,d,e;
    while(t--)
    {
        cin>>a>>b>>c>>d>>e;
        long long x=stoi(a),y=stoi(c),z=stoi(e);
        if(x<0)
            x=z-y;
        if(y<0)
            y=z-x;
        if(z<0)
            z=x+y;
        printf("%lld + %lld = %lld\n",x,y,z);

    }
    return 0;
}
