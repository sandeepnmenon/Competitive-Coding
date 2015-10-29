#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int a[n+1];
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        int i=1;
        int ans=0;
        while(i<=n)
        {
            if(!a[i])
            {
                if(i==1)
                {
                    if(n>1 and !a[2])
                    {
                        ans++;
                        a[2]=1;
                    }


                }
                else
                {
                    if(!a[i-1] and !a[i+1])
                    {
                        ans++;
                        a[i]=1;
                    }
                }
            }
            i++;
        }

        printf("%d\n",ans);
    }
    // your code goes here
    return 0;
}
