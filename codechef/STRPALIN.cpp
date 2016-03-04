#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cin>>a>>b;
        int s1[26]={0},s2[26]={0};
        for(int i=0;i<a.length();++i)
            s1[a[i]-'a']=1;
        for(int i=0;i<b.length();++i)
            s2[b[i]-'a']=1;
        bool flag=false;
        for(int i=0;i<26;++i)
            if(s1[i]==1 and s2[i]==1)
        {
            flag=true;
            break;
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
