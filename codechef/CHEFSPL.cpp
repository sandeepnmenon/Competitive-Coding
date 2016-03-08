#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long d;
    string s;
    scanf("%lld",&d);
    while(d--)
    {
        cin>>s;
        long long len=s.length();
        bool flag=true;
        if(len==1)
        {
            printf("NO\n");
            continue;
        }
        if(len%2==0)
        {
            for(long long i=0,j=len/2;i<len/2,j<len;++i,++j)
                if(s[i]!=s[j])
            {
                flag=false;
                break;
            }
        }
        else
        {
            bool fflag=true,mflag=true,lflag=true;
            for(long long i=0,j=len/2+1;i<len/2,j<len;++i,++j)
                if(s[i]!=s[j])
            {
                mflag=false;
                break;
            }
            flag=true;
            for(long long i=0,j=len/2+1;i<len/2+1,j<len;++i,++j)
                if(s[i]!=s[j])
            {
                if(!flag)
                {
                    fflag=false;
                    break;
                }
                j--;
                flag=false;
            }
            flag=true;
            for(long long i=0,j=len/2;i<len/2,j<len;++i,++j)
                if(s[i]!=s[j])
                {
                    if(!flag)
                    {
                        lflag=false;
                        break;
                    }
                    i--;
                    flag=false;
                }
            flag=fflag or mflag or lflag;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
