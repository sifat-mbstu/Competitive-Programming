#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll to[64];
int main()
{
    to[0]=1;
    for(int i=1; i<=32; i++)
    {
        to[i] = to[i-1] * 2;
    }
    ll TC;
    cin >> TC;
    while(TC--){
    ll n,k;
    scanf("%lld %lld",&n, &k);
    ll res[100];
    if(k==-1) printf("0\n");
    else
    {
        for(int i=2; i<n+2; i++)
        {
            ll v = to[i];
            ll a = k%v;
            ll rem = v/4;
            ll v1 = 0, v2 = rem, v3 = rem*2, v4 = rem*3, v5 = rem*4;
            ll now;
            if(a>=v1 && a<v2) now = 0;
            else if(a>=v2 && a<v3) now = 1;
            else if(a>=v3 && a<v4) now = 1;
            else if(a>=v4 && a<v5) now = 0;
            res[i-2] = now;
        }
        ll sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += (res[i] * to[i]);
        }
        printf("%lld\n",sum);
//        cout << sum << endl;
    }
    }
}
