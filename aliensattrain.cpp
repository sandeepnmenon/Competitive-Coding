#include<bits/stdc++.h>
using namespace std;
long long st[1003],en[1003],mud[1003];
int main(){
    long long t;
    scanf("%lld",&t);
    long long At,Bt;
    while(t--)
    {
        scanf("%lld %lld",&At,&Bt);
        long long len=0,max_len=0,meet=0,max_meet=0,ppl;
        queue<long long> stat;
        while(At--)
        {
            scanf("%lld",&ppl);
            stat.push(ppl);
            len++;
            if(meet+ppl<=Bt)
            {
                meet+=ppl;
                if(max_len<len){
                max_meet=meet;
                max_len=len;}
            }
            else
            {
                    meet+=ppl;
                    while(meet>Bt)
                    {
                        meet-=stat.front();
                        stat.pop();
                    }
            }
        }
        printf("%lld %lld\n",max_meet,max_len);

    }

    return 0;
}
