#include<bits/stdc++.h>
#define max 10003
using namespace std;
long long tree[10004];

int main() {

    int t;
    scanf(" %d",&t);
    long long q,n,u,l,r,val,ind;
    while(t--){
        scanf(" %lld %lld",&n,&u);
        fill(tree,tree+n+1,0);
        while(u--){
            scanf(" %lld %lld %lld",&l,&r,&val);
            tree[l]+=val;
            tree[r+1]-=val;
        }
        for(int i=1;i<n;++i)
            tree[i]+=tree[i-1];
        scanf(" %lld",&q);
        while(q--){
            scanf(" %lld",&ind);
            printf("%lld\n",tree[ind]);
            
        }
        
    }
    return 0;
}
