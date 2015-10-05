#include<bits/stdc++.h>
using namespace std;
long long a[100005],sum[100005];
int main() {

   int t;
   scanf("%d",&t);
   while(t--)
   {
       long long n;
        scanf("%lld",&n);
        sum[0]=0;
        for (long long i=0;i<n;i++){
			scanf("%lld",&a[i]);
			sum[i+1]=i+1+sum[i];
        }
        a[n]=0;
        long long i=0,cnt=1,ans=0;
        while(i<n)
        {
            if(a[i]<a[i+1])
            {
                cnt++;
            }
            else
            {
                ans+=sum[cnt];
                cnt=1;
            }
            i++;
        }
        printf("%lld\n",ans);

   }
    return 0;
}
