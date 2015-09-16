#include <iostream>

#include<cstdio>

#include<cmath>

using namespace std;



int main() {

	// your code goes here

	int t;

	scanf("%d",&t);

	while(t--)

	{

	    double p,res;

	    long long m;

	    scanf("%lld %lf",&m,&p);

	    res=(1-pow(-p,m))/(1+p);

	    printf("%lf %lf\n",res*1e9,(1-res)*1e9);

	}

	return 0;

}

