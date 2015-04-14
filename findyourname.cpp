#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n,q;
    char a[1003],str[1003];
    cin>>t;
    while(t--)
        {
        int has[26]={0};
        cin>>n>>a;
        for(int i=0;a[i]!='\0';++i)
            has[a[i]-97]++;
        cin>>q;
        while(q--)
            {
            cin>>str;
            int ch[26]={0};
            bool flag=1;
            for(int i=0;str[i]!='\0';++i)
                ch[str[i]-97]++;
            for(int i=0;i<26;++i)
            {
                if(ch[i]>has[i])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }
    }
    return 0;
}
