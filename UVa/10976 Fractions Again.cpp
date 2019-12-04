#include<bits/stdc++.h>
using namespace std;
#define pf printf
#define sf scanf
#define ll long long
ll lcm(ll u, ll v)
{
    ll a;
    ll p = u;
    ll q = v;
    while(v!=0)
    {
        a = u % v;
        u = v;
        v = a;
    }
    return (p*q)/u;
}
int main()
{
    ll k, RES[10005], K[10005], I[10005];
    while(sf("%lld",&k)==1)
    {
        ll cnt = 0;
        for(ll i=k+1; i<=k*2; i++)
        {
            ll hor = lcm(k,i);
            ll lob = (hor/k) - (hor/i);
            //pf("hor = %lld lob = %lld\n",hor, lob);
            //getchar();
            if(hor % lob == 0)
            {
                ll res = hor/lob;
                RES[cnt] = res;
                K[cnt] = k;
                I[cnt] = i;
                //pf("1/%lld = 1/%lld + 1/%lld\n",k,res,i);
                cnt++;
            }
        }
        pf("%lld\n",cnt);
        for(ll i= 0; i<cnt; i++)
        {
            pf("1/%lld = 1/%lld + 1/%lld\n",K[i],RES[i],I[i]);
        }
    }
}
