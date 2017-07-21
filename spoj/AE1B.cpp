#include <bits/stdc++.h>
#define mod 1000000007
#define twoInv 500000004
using namespace std;
int a[1003];
int main()
{
    ios::sync_with_stdio(false);
    int n,k,s;
    cin>>n>>k>>s;
    for(int i=0;i<n;++i)
        cin>>a[i];

    int total=k*s;
    sort(a,a+n);

    int i=n-1;
    while(total>0)
    {
        total-=a[i--];

    }
    cout<<n-i-1<<endl;
	return 0;
}
