    #include<bits/stdc++.h>
    #define Nmax 100
    #define ll long long
    using namespace std;

    const int nmax = 100010;
    const int inf = 1000000007;
    int n, a[nmax], q, type, pos, val, step;
    ll remain[nmax], rem;
    long double dig[nmax];
    int sq;

    ll binpow(ll a, ll b, ll c){
       ll r =1 ;
       while (b){
         if (b&1) r*=a;
         a*=a;
         r%=c;
         a%=c;
         b>>=1;
       }
       return r;
    }

    ll inverse(ll a){
      return binpow(a, inf-2, inf);
    }


    int main()
    {
        srand(time(0));

        scanf("%d\n", &n);
        sq = sqrt(n+0.0)+1;
        for (int i=1; i<=n; i++) {

            scanf("%d", a+i);
        }

        for (int j=1; j<=sq; j++){
            pos = 1;
            rem = 1;
            long double sum=0;
    //sum=log10(a[1]*a[1+j]*a[1+j+j]*a[1+j+j+j]...)=log10(a[1])+log10(a[1+j])+log10(a[1+j+j])....
            while (pos<=n){
               sum+=log10(a[pos]);
               rem = (rem*a[pos])%inf;
               pos+=j;
            }
            remain[j] = rem;
            dig[j] = sum;
        }
        scanf("%d", &q);
    //We have 2 parts
    //if step is more that sqrt(n) - brute force
    //else will just output the answer precalculated earlier
    //also during all updates we should maintain our "precalculation" structure

        while (q--){
          scanf("%d", &type);
          if (type==1){
            scanf("%d %d", &pos, &val);
            ll inv = inverse(a[pos]); //Inverse element for a[pos]
            if (pos==1) {
                for (int i=1; i<=sq; i++){
                    remain[i]*=inv;
                    remain[i]%=inf;
                    remain[i]*=val;
                    remain[i]%=inf;
                    dig[i]-=log10(a[1]+0.0);
                    dig[i]+=log10(val+0.0);
                }
            } else {
                for (int i=1; i<=min(pos-1, sq); i++){
                   if ((pos-1)%i==0){
                      dig[i]-=log10(a[pos]+0.0);
                      dig[i]+=log10(val+0.0);
                      remain[i]*=inv;
                      remain[i]%=inf;
                      remain[i]*=val;
                      remain[i]%=inf;
                   }
                }
            }
            a[pos]=val;
          } else
          {
            scanf("%d", &step);
            if (step>sq){
    		rem = 1;
    		pos = 1;
    		long double sum=0;
    		while (pos<=n){
    		   sum+=log10(a[pos]+0.0);
    		   rem = (rem*a[pos])%inf;
    		   pos+=step;
    		}
    		rem = (rem+inf)%inf;
    		int first = (int)(pow(10.0, sum-floor(sum))+0.000000001);
    		if (first==10) first=1;
    		printf("%d %d\n", first, rem);
    		//cout << first << " " << rem << endl;
    		}
    		else {
    		   int first = (int)(pow(10.0, dig[step]-floor(dig[step]))+0.000000001);
    		   if (first==10) first=1;
    		   printf("%d %d\n", first, remain[step]);
    		   //cout << first << " " << remain[step] << endl;
    		  }
          }

        }



    }
