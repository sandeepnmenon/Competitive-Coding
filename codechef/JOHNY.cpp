#include<bits/stdc++.h>
using namespace std;
long long a[105];
int binarySearch(int key,int n)
{
    int l=0,r=n-1,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
            r=mid;
        else
            l=mid+1;
    }
    return -1;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%lld",&a[i]);
        scanf("%d",&k);
        long long key=a[k-1];
        sort(a,a+n);
        int ans=binarySearch(key,n);
        printf("%d\n",ans+1);
    }
    return 0;
}
