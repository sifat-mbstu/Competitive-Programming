///Accepted
#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define SQ(n) (n*n)
#define ll long long
#define llu unsigned long long

#define pi 2.0*acos(0.0)

#define all(a) a.begin(),a.end()
#define _max(a,b,c) Max(a,Max(b,c))
#define _min(a,b,c) Min(a,Min(b,c))

#define FOR(i,a,b) for(int i=a;i<b; i++)

#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d%d",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

#define sff(a) scanf("%lld",&a)
#define sff2(a,b) scanf("%lld%lld",&a,&b)
#define sff3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define sff4(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)

#define total_overlap(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define no_overlap(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW

#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
#define MOD 1000000007
#define inf INT_MAX/3

ll fun(ll n)
{
    return (n*(n+1)/2);
}

ll any_fun(ll n, ll a, ll d)
{
    return ( (n) * ( (2*a) + ( (n-1) * d ) ) )/2;
}

int main()
{
    ll TC, ind = 0;
    sff(TC);
    while(TC--)
    {
        ll n,k;
        sff2(n,k);
//        ll nn = n/(k*2);
//        ll m = nn*k;
//        ll a = fun(2*k-1) - fun(k-1);
//        ll b = fun(4*k-1) - fun(3*k-1);
//        ll d = b-a;
//        ll sum = fun(n);
//        sum -= 2*((n*m) - any_fun(nn,a,d));
        printf("Case %lld: %lld\n",++ind,n*k/2);
    }
}
