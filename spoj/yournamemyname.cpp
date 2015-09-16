#include<bits/stdc++.h>
using namespace std;
bool issub(string a,string b)
{
    int j=0;
    for(int i=0;i<a.length() && j<b.length();++i)
        if(a[i]==b[j])
            j++;
    if(j==b.length())
        return true;
    else
        return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        if(issub(a,b) or (issub(b,a)))
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}
