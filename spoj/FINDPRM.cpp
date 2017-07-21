#include <bits/stdc++.h>
#define mod 1000000007
#define MAX 10000000
using namespace std;
long long n;
bool prime[MAX+1];
long long noOfPrimes[MAX+1];
void init()
{
    for(long long i=3;i*i<=MAX;i+=2)
        if(!prime[i])
            for(int j=i*i;j<=MAX;j+=2*i)
                prime[j]=true;

    noOfPrimes[1]=noOfPrimes[0]=0;
    noOfPrimes[2]=1;
    for(long long i=3;i<=MAX;++i)
        if(!prime[i] and i&1)
            noOfPrimes[i]=noOfPrimes[i-1]+1;
        else
            noOfPrimes[i]=noOfPrimes[i-1];


}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    init();
    while(t--)
    {
        cin>>n;
        cout<<noOfPrimes[n]-noOfPrimes[(n>>1)]<<endl;

    }
	return 0;
}
