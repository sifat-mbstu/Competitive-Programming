#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000100
ll a[mx];
map <ll, ll> Map;
int main()
{
    ll n, TC;
    cin >> TC;
    while(TC--){
    Map.clear();
    scanf("%lld",&n);
    for(ll i=1; i<=n; i++) {scanf("%lld",&a[i]);}
    ll rep = 1;
    ll res = 0;
    for(ll i=1;i<=n; i++)
    {
        if(Map[a[i]]<rep) {Map[a[i]] = i;}
        else{
            ll dhara = i-rep;
            res += dhara* (dhara + 1)/2;
            dhara = i - Map[a[i]] - 1;
            res -= dhara* (dhara + 1)/2;
            rep = Map[a[i]] + 1;
            //printf("%I64d\n",res);
            Map[a[i]] = i;
        }
    }
    ll dhara = n - rep + 1;
    res += dhara* (dhara + 1)/2;
    printf("%lld\n",res);
    }
}
