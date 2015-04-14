#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned int comb(unsigned int n,unsigned int r)
{
	if(r==0)
		return 1;
	return n*comb(n-1,r-1)/r;

}int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cout<<comb()
}
    return 0;
}
