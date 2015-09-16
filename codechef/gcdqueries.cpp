    #include <iostream>
    using namespace std;
    int gcd(long a,long b)
    {
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
    }

    int main() {
    // your code goes here
    long n,t,q,l,r,hcf;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        long a[n];
        for(long i=0;i<n;++i)
            cin>>a[i];
            while(q--)
            {

                cin>>l>>r;
                l--;r--;
                hcf=0;
                for(long i=0;i<n;++i)
                {
                    if(i>=l&&i<=r)
                        continue;
                    hcf=gcd(a[i],hcf);
                    if(hcf==1)
                        break;
                }
                cout<<hcf<<endl;
            }

    }
    return 0;
    }
