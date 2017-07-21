#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long n;
    string s;
    scanf("%d",&t);
    map<string,long long> m;
    while(t--)
    {
        scanf(" %lld",&n);
        m.clear();
        for(long long i=0;i<n;++i)
        {
            getline(cin,s);
            if(!isdigit(s[0]))
            {
                //cout<<s[0]<<endl;
                i--;
                continue;
            }
            if(m.find(s)==m.end())
                m[s]=1;
            else
                m[s]++;
        }
        for(map<string,long long>:: iterator it=m.begin();it!=m.end();++it)
            printf("%s %lld\n",it->first.c_str(),it->second);
    }
    return 0;
}
