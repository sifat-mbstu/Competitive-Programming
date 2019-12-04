#include<bits/stdc++.h>
using namespace std;
#define mxx 4000005
#define ll long long
bool vis[mxx];
ll phi[mxx], res[mxx];

void PHI(ll n)
{
    ll i, j;

    for(ll i = 1; i <= n; i++)
        phi[i] = i;

    vis[1] = 1;
    for(ll i = 2; i <= n; i++)
    {
        if(vis[i] == 0)
        {
            phi[i] = i-1;
            for(j = i+i; j <= n; j += i)
            {
                vis[j] = 1;
                phi[j] = phi[j]/i * (i - 1);
            }
        }
    }
}

void gcd_extreme(ll n)
{
    for(ll d = 1; d <= n/2; d++)
    {
        for(ll i = 2; i * d <= n; i++)
        {
            ll x = i * d;
            res[x] += d * phi[x/d];
        }
    }
    for(ll i = 2; i <= n; i++)
        res[i] += res[i - 1];
}

int main()
{
    PHI(4000001);
    gcd_extreme(4000001);
    ll n;

    while(scanf("%lld", &n) == 1)
    {
        if(n == 0)
            break;

        printf("%lld\n",res[n]);
    }
    return 0;
}
