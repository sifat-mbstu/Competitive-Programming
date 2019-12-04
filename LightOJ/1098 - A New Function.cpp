///AC
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define FO freopen("out.txt", "w", stdout)

ll mod = 1000000007;

ll n,m;
ll Bigmod(ll N,ll P, ll M)
{
	if(P==0) return 1;
	if(P%2==0)
	{
		ll ret= Bigmod(N,P/2,M);
		return ((ret%M)*(ret%M))%M;
	}
	else return ((N%M)*(Bigmod(N,P-1, M)%M))%M;
}
ll hisab(ll num)
{
    ll ini = num;
    ini++;
    ll sq = sqrt(num);
    ll res = 1;
    for(ll i=2; i<=sq; i++)
    {
        if(num%i==0)
        {
            ll cnt = 0;
            while(num%i==0 && num!=1)
            {
                num = num/i;
                cnt++;
            }
            cnt *= m;
//            printf("pr = %lld .. cnt = %lld\n",i,cnt);
            ll n1 = Bigmod(i,cnt+1,mod)-1;
            n1 += mod;
            n1 %= mod;
            ll n2 = Bigmod(i-1,mod-2,mod);
            ll now = (n1%mod)*(n2%mod)%mod;
            res *= now;
            res %= mod;
        }
    }
    if(num!=1)
    {
            ll n1 = Bigmod(num,m+1,mod)-1;
            n1 += mod;
            n1 %= mod;
            ll n2 = Bigmod(num-1,mod-2,mod);
            ll now = (n1%mod)*(n2%mod)%mod;
            res *= now;
            res %= mod;
    }
    res -= ini;
    return res;
}
int main()
{
//    FO;
    ll tc,idx=0;
    scanf("%lld",&tc);
    while(tc--){
    m = 1;
    scanf("%lld",&n);
//    for(ll n=1; n<=30; n++){
    ll ans = 0;
    for(ll i=2; i<=n; i++)
    {
        ans += hisab(i);
    }
    printf("Case %lld: %lld\n",++idx,ans);
    }
//    }
    return 0;
}
