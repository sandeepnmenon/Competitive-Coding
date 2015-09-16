
#include<iostream>
using namespace std;
int main()
{
    unsigned int n,m,x,y,z,freq;
    cin>>n>>m;
    char a[100003];
    cin>>a;
    while(m--)
    {
        cin>>x>>y>>z;
        freq=0;
        if(x==1)
        {
            y--;

            a[y]=z+48;
        }

        else if(x==2)
        {
            freq=0;
            unsigned int num,len=z-y+1,sum=0;
            y--;z--;
            for(long i=y;i<=z;++i)
            {

                sum+=a[i]-48;
                if(sum%3==0)
                 {
                    if(sum==0)
                        continue;
                        freq++;
                 }
                if((a[i]-48)%3==0)
                {
                    freq++;
                }
            }


        }
    }
    return 0;
}

