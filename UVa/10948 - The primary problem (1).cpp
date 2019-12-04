#include<bits/stdc++.h>
using namespace std;
#define mx 10000100
#define ll long long
vector<ll>prime;
bool a[mx];
void sieve()
{
    a[1] = a[0] = 1;
    prime.push_back(2);
    for(ll i=4; i<=mx; i+=2)
        a[i] = 1;
    for(ll i=3; i<=mx; i++)
    {
        if(a[i] == 0)
        {
            prime.push_back(i);
            for(ll j = i * i ; j<=mx; j+=i)
                a[j] = 1;
        }
    }
}
int main()
{
    sieve();
    ll n;
    while(cin >> n){
    if(!n)break;
    bool t = 1;
    ll res1,res2;
    for(ll i=0; i<prime.size(); i++)
    {
        ll p = prime[i];
        if(p > n)
        {
            t = 0;
            break;
        }
        if(!a[n-p])
        {
            res1 = p;
            res2 = n-p;
            break;
        }
    }
    printf("%lld:\n",n);
    if(t) printf("%lld+%lld\n",res1,res2);
    else printf("NO WAY!\n",res1,res2);
    }
}
