#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin >> t;
    long long sum=1;
    int j=2;
    for(int i=2;i<=t;++i)
        {
            sum+=j;
            if(i&1)
                j++;

    }
    printf("%lld",sum);
    // your code goes here
    return 0;
}
