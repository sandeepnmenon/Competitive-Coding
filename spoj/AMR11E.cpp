#include <bits/stdc++.h>
#define mod 1000000007
#define MAX 3000
using namespace std;
int prime[MAX];
vector<int> ans;
void sieve()
{
    fill(prime,prime+MAX,0);
    for(int i=2;i<MAX;++i)
    {
        if(prime[i]==0)
        {
            for(int j=i+i;j<MAX;j+=i)
                prime[j]++;
        }
    }

    for(int i=30;i<MAX;++i)
    {
        if(prime[i]>=3)
            ans.push_back(i);
        if(ans.size()==1000)
            break;
    }
}
int main()
{
    ios::sync_with_stdio(false);

    int t,n;
    cin>>t;
    sieve();
    while(t--)
    {
        cin>>n;
        cout<<ans[n-1]<<endl;
    }
	return 0;
}
