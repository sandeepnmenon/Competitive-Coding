#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	ios::sync_with_stdio(false);
	int t;
    long long n,m;
    cin>>t;
	while(t--)
	{
	    cin>>n>>m;
	    long long ar=n*m-1;
	    if(ar&1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
	}
	return 0;
}
