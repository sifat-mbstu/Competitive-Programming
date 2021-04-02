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

#define sf(a) scanf("%lld",&a)
#define sf2(a,b) scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)

#define total_overlap(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define no_overlap(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW

#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define vi vector<ll>
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
#define MOD 1000000007
#define inf ll_MAX/3
#define mx 100010
ll arr[mx];
ll tree[mx*4];
ll lazy[mx*4];
void build(ll lo, ll hi, ll pos)
{
    if(lo>hi) return;
    if(lo==hi)
    {
        tree[pos] = arr[lo];
        return;
    }
    ll mid = (lo+hi)/2;
    build(lo, mid, pos*2);
    build(mid+1, hi, pos*2+1);
    tree[pos] = tree[pos*2] + tree[pos*2+1];
}
void update_lazy(ll qlo ,ll qhi, ll lo, ll hi, ll val, ll pos)
{
    if(no_overlap(qlo, qhi, lo, hi)) return;
    if(total_overlap(qlo, qhi, lo, hi))
    {
        tree[pos] += ((hi-lo+1) * val);
        lazy[pos] += val;
        return;
    }
    ll mid = (lo+hi)/2;
    update_lazy(qlo, qhi, lo, mid, val, pos*2);
    update_lazy(qlo, qhi, mid+1, hi, val, pos*2+1);
    tree[pos] = tree[pos*2] + tree[pos*2+1] + ((hi-lo+1) * lazy[pos]);
}

ll query(ll qlo, ll qhi, ll lo, ll hi, ll carry, ll pos)
{
    if(no_overlap(qlo, qhi, lo, hi)) return 0;
    if(total_overlap(qlo, qhi, lo, hi))
    {
        return tree[pos]+(carry*(hi-lo+1));
    }
    ll mid = (lo+hi)/2;
    ll a = query(qlo, qhi, lo, mid, carry+lazy[pos], pos*2);
    ll b = query(qlo, qhi, mid+1, hi, carry+lazy[pos], pos*2+1);
    return a+b;
}
int main()
{
    ll TC, ind =0;
    scanf("%lld",&TC);
    while(TC--){
    memset(lazy,0,sizeof(lazy));
    memset(tree,0,sizeof(tree));
    ll n;
    scanf("%lld",&n);
    build(0,n-1,1);
    printf("Case %lld:\n",++ind);
    ll q;
    scanf("%lld",&q);
    while(q--)
    {
        ll choise;
        scanf("%lld",&choise);
        if(choise == 0)
        {
            ll loc1, loc2, val;
            scanf("%lld %lld %lld",&loc1, &loc2, &val);
            update_lazy(loc1, loc2, 0, n-1, val, 1);
        }
        else
        {
            ll loc1, loc2;
            scanf("%lld %lld",&loc1, &loc2);
            printf("%lld\n",query(loc1, loc2, 0, n-1, 0,1));
        }
    }

    }
}
