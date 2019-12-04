#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 10000010
vector<ll>prime;

bool a[mx];
void sieve()
{
    a[1] = 1;
    prime.push_back(2);
    for(ll i=4; i<=mx; i+=2)
        a[i] = 1;
    for(ll i=3; i<mx; i++)
    {
        if(a[i] == 0)
        {
            prime.push_back(i);
            for(ll j = i * i; j<mx; j+= 2*i)
                a[j] = 1;
        }
    }
}
ll factor_print(ll n)
{
//    freopen();
    ll sq = sqrt(n);
    for(ll i=0; prime[i]<=n/2 && i<prime.size(); i++)
    {
        ll pr = prime[i];
        while(!(n%pr))
        {
            printf("    %lld\n",pr);
            n /= pr;
        }
        // if(n==1)break;
    }
//    if(n>1)
        printf("    %lld\n",n);
}
int main()
{
    sieve();
    ll n;
    bool t = 0;
    while(scanf("%lld",&n))
    {
        if(n==-1)break;
        //if(t)printf("\n");
        factor_print(n);
        printf("\n");
        //t = 1;
    }
}
