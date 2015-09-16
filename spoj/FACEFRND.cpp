#include<iostream>
#include<set>
using namespace std;

int main()
{
    int n,i=0,m,no;
    cin>>n;
    no=n;
    set <int> f;
    int a[n];
    while(n--)
    {
        cin>>a[i]>>m;
        int b[m];
        for(int j=0;j<m;++j)
        {
            cin>>b[j];
            f.insert(b[j]);
        }
        i++;

    }
    for(i=0;i<no;++i)
        f.erase(a[i]);

    cout<<f.size();
    return 0;
}
