#include<bits/stdc++.h>
using namespace std;
int arr[105][105];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<=n;++i)
            for(int j=0;j<=n;++j)
        {
            arr[i][j]=0;
            if(i>0 and j>0 and i>=j)
                scanf("%d",&arr[i][j]);
        }
        for(int i=2;i<=n;++i)
            for(int j=1;j<=i;++j)
                arr[i][j]=arr[i][j]+max(arr[i-1][j],arr[i-1][j-1]);

        int res=arr[n][1];
        for(int i=2;i<=n;++i)
            res=max(res,arr[n][i]);
        printf("%d\n",res);
    }
    return 0;
}
