#include<cstdio>
int main()
{
int t;long long b,a;scanf("%d",&t);
while(t--)
{
scanf("%lld %lld",&a,&b);
 long long d=1;
 while(b){
      if(b%2)
        d=(d*a)%10;
     b >>=1;
    a=(a*a)%10;
    }
 printf("%lld\n",d%10);
 }
  return 0;
}
