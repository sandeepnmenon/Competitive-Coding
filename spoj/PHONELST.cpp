#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        scanf("%d",&n);
        string x;
        for(int i=0;i<n;++i)
        {
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        string pref=v[0],temp;
        int len;
        bool flag=false;
        for(int i=1;i<n;++i)
        {
            len=pref.length();
            temp=v[i].substr(0,len);
            if(temp==pref)
            {
                flag=true;
                break;
            }
            pref=v[i];
        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");

    }
    return 0;
}
