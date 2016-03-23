#include<bits/stdc++.h>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t,n,totxor,inp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        totxor=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&inp);
            totxor= totxor xor inp;
        }
        if(totxor==0 or n%2==0)
            printf("First\n");
        else
            printf("Second\n");
    }
    return 0;
}
