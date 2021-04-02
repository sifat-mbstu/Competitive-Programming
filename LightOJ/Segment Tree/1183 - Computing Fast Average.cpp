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

#define FOR(i,a,b) for(ll i=a;i<b; i++)

#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d%d",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

#define total_overlap(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define no_overlap(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW

#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define vi vector<ll>
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
#define MOD 1000000007
#define inf ll_MAX/3
#define mx 100011
ll in[mx];
ll tree[mx*4];
ll lazy[mx*4];

void update_lazy(ll qlow, ll qhi, ll lo, ll hi, ll delta, ll pos)
{
    if(lo>hi) return;
    if(lazy[pos]!=-1)
    {
        tree[pos] = lazy[pos] * (hi-lo+1);
        if(lo != hi)
        {
            lazy[2*pos+1] = lazy[pos];
            lazy[2*pos+2] = lazy[pos];
        }
        lazy[pos] = -1;
    }
    if(no_overlap(qlow, qhi, lo, hi)) return;
    if(total_overlap(qlow, qhi, lo, hi))
    {
        tree[pos] = delta * (hi-lo+1);
        if(lo!=hi)
        {
            lazy[2*pos+1] = delta;
            lazy[2*pos+2] = delta;
        }
        return;
    }
    ll mid = (lo+hi)/2;
    update_lazy(qlow, qhi, lo, mid,delta, 2*pos+1);
    update_lazy(qlow, qhi,mid+1, hi,delta, 2*pos+2);
    tree[pos] = tree[pos*2+1] + tree[pos*2+2];
}

ll query(ll qlo, ll qhi, ll lo, ll hi, ll pos)
{
    if(lo > hi) {return 0;}
    if(lazy[pos]!=-1)
    {
        tree[pos] = lazy[pos] * (hi-lo+1);
        if(lo!=hi)
        {
            lazy[pos*2+1] = lazy[pos];
            lazy[pos*2+2] = lazy[pos];
        }
        lazy[pos] = -1;
    }
    if(no_overlap(qlo, qhi, lo, hi)) {return 0;}
    if(total_overlap(qlo, qhi, lo, hi)) {return tree[pos];}
    ll mid = (lo+hi)/2;
    return (query(qlo, qhi, lo, mid, 2*pos+1) + query(qlo, qhi, mid+1, hi, 2*pos+2));
}

int main()
{
    ll TC, ind = 0;
    cin >> TC;
    while(TC--){
    memset(tree,0,sizeof(tree));
    memset(lazy,-1,sizeof(lazy));
    ll n, q, choise;
    scanf("%lld",&n);
    scanf("%lld",&q);
    printf("Case %lld:\n",++ind);
    while(q--)
    {
        scanf("%lld",&choise);
        if(choise == 1)
        {
            ll loc1, loc2, val;
            scanf("%lld %lld %lld",&loc1, &loc2, &val);
            update_lazy(loc1, loc2, 0, n-1, val, 0);
        }
        else
        {
            ll loc1, loc2;
            scanf("%lld %lld",&loc1, &loc2);
            if(loc1 > loc2) swap(loc1, loc2);
            ll numerator  = query(loc1, loc2, 0, n-1, 0);
            ll denominator = loc2 - loc1 + 1;
            ll GCD = __gcd(numerator, denominator);
            numerator /= GCD;
            denominator /= GCD;
            if(denominator!=1)
            {
                printf("%lld/%lld\n",numerator, denominator);
            }
            else
            {
                printf("%lld\n",numerator);
            }
        }
    }
    }
}
