#include<bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t;
    float p,s,lb,h;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%f %f",&p,&s);
        h=(p/2-sqrt(p*p/4-6*s))/6;
        lb=s/2-h*p/4+h*h;
        printf("%.2f\n",lb*h);
    }
    return 0;
}
