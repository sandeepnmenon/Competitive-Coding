#include<iostream>
using namespace std;
int main()
{
    string str;
    cin>>str;

    for(int i=0;i<str.length();++i)
    {
        if(str[i]=='B')
            if(str[i+1]=='a')
                cout<<char(90+2);
            else
                cout<<char(90+1);
        if(str[i]=='C')
            if(str[i+1]=='a')
                cout<<char(90+3);
            else
                cout<<char(90+4);
        if(str[i]=='N')
            cout<<char(90+5);
    }
    return 0;
}
