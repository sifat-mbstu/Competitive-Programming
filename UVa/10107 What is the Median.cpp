///Have to submit
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ar[10100];

int main()
{
    ll i=0,n;
    while(scanf("%lld",&ar[i++])==1)
    {
        sort(ar,ar+i);
        if(i%2==0)
        {
            n = i/2;
            n = ar[n] + ar[n-1];
            n /= 2;
            printf("%lld\n",n);
           // cout << n << endl;
        }
        else{
                n = i/2;
                printf("%lld\n",ar[n]);
                //cout << ar[n] << endl;
        }
    }
}
