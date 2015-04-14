#include<stdio.h>
unsigned long long power(unsigned long k,unsigned long i)
{
    unsigned long long res=1,j;
    for(j=0;j<i;++j)
        res*=k;
    return res;


}
int main()
{
    unsigned long t,k,i,num,rem,n;
    scanf("%lu",&t);
    while(t--)
    {
        scanf("%lu%lu",&n,&k);
        num=0;
        while(n!=0)
        {
            i=0;
            while(power(k,i)<=n)
                i++;
            i--;
            rem=power(k,i);
            num+=(n/rem);
            n=n-((n/rem)*rem);

        }
        printf("%lu\n",num);
    }
    return 0;
}
