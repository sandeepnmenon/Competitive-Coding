<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

long long dp[100];
int main() {
	//code
	int t,n;
	ios::sync_with_stdio(false);

	dp[1]=1;
	dp[2]=2;
	dp[3]=3;

	cin>>t;
	while(t--){
	    cin>>n;
	    for(int i=4;i<=n;++i)
	        dp[i]=dp[i-1]+dp[i-2];
	    cout<<dp[n]<<endl;
	}
	return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;

long long dp[100];
int main() {
	//code
	int t,n;
	ios::sync_with_stdio(false);

	dp[1]=1;
	dp[2]=2;
	dp[3]=3;

	cin>>t;
	while(t--){
	    cin>>n;
	    for(int i=4;i<=n;++i)
	        dp[i]=dp[i-1]+dp[i-2];
	    cout<<dp[n]<<endl;
	}
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
