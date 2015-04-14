#include <cstdio>
#include<algorithm>

unsigned int xor_sum(int a[],unsigned int x,unsigned int n)
{
    unsigned int res=a[x]+1;
    for(unsigned int i=0;i<n;++i)
        if(i!=x)
            res=res^a[i];
    return res;
}
int main() {
    unsigned int t,n,d,sum;
    scanf("%d",&t);
    while(t--)
    {
            sum=0;
            scanf("%u%u",&n,&d);
            if(n==1)
            {
                for(int i=1;i<d;++i)
                    sum+=(i*i);
            }
            /*
            else if(n==2)
            {
                int i=0,j=0;
                while(i!=d-1||j!=d-1)
                {
                    if(i==d-1)
                    {

                     sum+=(((j+1)^i)*(i+j+1));
                     j++;
                     continue;
                    }
                    if(j==d-1)
                    {
                        sum+=(((i+1)^j)*(i+1+j));
                        i++;
                        continue;
                    }

                    if(((i+1)^j)*(i+1+j)<((j+1)^i)*(i+j+1))
                       if(i<d)
                         {

                            sum+=(((i+1)^j)*(i+1+j));
                            i++;
                         }
                        else
                           {

                            sum+=(((j+1)^i)*(i+j+1));
                            j++;
                           }
                    else
                        if(j<d)
                            {sum+=(((j+1)^i)*(i+j+1));
                            j++;
                            }
                        else
                            {sum+=(((i+1)^j)*(i+1+j));
                                i++;
                            }

                }
            }*/
            else
            {
                unsigned int pos[3]={0},res=0,tr,m;
                while(res!=n*(d-1))
                {
                    m=0;
                    for(unsigned int i=0;i<n;++i)
                    {
                        if(m<xor_sum(pos,i,n))
                        {


                            m=xor_sum(pos,i,n);
                            tr=i
                        }
                    }
                    pos[tr]++;
                    res=accumulate(pos,pos+n);
                    sum+=m;

                }
            }
            printf("%u\n",sum);
    }
    return 0;
}
