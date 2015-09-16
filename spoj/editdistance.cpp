#include<bits/stdc++.h>
using namespace std;
int dp[2003][2003];
string a,b;
int solve(int n ,int m){


	int i,j;
	for( i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			if( i==0)
				dp[i][j]=j;
			else if(j==0)
				dp[i][j]=i;
			else if( a[i-1]==b[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min( dp[i][j-1],min( dp[i-1][j] , dp[i-1][j-1]))+1;
		}
	}
	return dp[n][m];
}

int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--)
    {


	cin>>a>>b;
	cout<<solve(a.length(),b.length())<<endl;
    }
	return 0;
}
