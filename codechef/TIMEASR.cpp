#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main() {

    long long t;
    scanf("%lld",&t);
    while(t--)
    {
        float a,ang,dif=1.0/120;

        scanf("%f",&a);
        for(int i=0;i<12;++i)
        {
            for(int j=0;j<60;++j)
            {
                ang=abs(30*i-11*j*0.5);
                if(ang>=180)
                    ang=360-ang;
                if(abs(ang-a)<=dif)
                {
                    if(i<10)
                        printf("0%d:",i);
                    else
                        printf("%d:",i);
                    if(j<10)
                        printf("0%d\n",j);
                    else
                        printf("%d\n",j);
                }
            }
        }
    }
    return 0;
}
