#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)

#define mx 100010
#define pii pair<ll,ll>
pii arr[mx];
    set<ll>Set;
    set<ll> :: iterator it;
    map<ll,ll>Mp;
ll qu[mx];
ll lazy[mx*4];
void update(ll node, ll b, ll e, ll i, ll j)
{
    if(e<i || b>j) return;
    if(b>=i && e<=j)
    {
        lazy[node]++;
        return;
    }
    ll mid = (b+e)/2;
    ll L = node*2;
    ll R = L+1;
    update(L, b, mid, i, j);
    update(R,mid+1,e, i, j);
}

ll query(ll node, ll b, ll e, ll i, ll j, ll v)
{
    if(e<i || b>j) return 0;
    if(b>=i && e<=j)
    {
        return v+lazy[node];
    }
    ll mid = (b+e)/2;
    ll L = node*2;
    ll R = L+1;
    ll ret1=0,ret2=0;
    if(i<=mid) ret1 = query(L, b, mid, i, j,v+lazy[node]);
    else ret2 = query(R,mid+1,e, i, j, v+lazy[node]);
    return ret1+ret2;
}

int main()
{
//    FO;
    ll TC, cas = 0;
    scanf("%lld",&TC);
    while(TC--){
    memset(lazy,0,sizeof(lazy));
    memset(arr,0,sizeof(arr));
    ll n,q;
    Set.clear();
    scanf("%lld %lld",&n, &q);
    for(ll i=0; i<n; i++)
    {
        ll a,b;
        scanf("%lld %lld",&a, &b);
        arr[i] = pii(a,b);
        Set.insert(a);
        Set.insert(b);
    }
    for(ll i=0; i<q; i++)
    {
        scanf("%lld",&qu[i]);
        Set.insert(qu[i]);
    }
    Mp.clear();
    ll idx = 1;
    for(it = Set.begin(); it!=Set.end(); it++)
    {
        Mp[(ll)*it] = idx++;
    }
    for(ll i=0; i<n; i++)
    {
        arr[i].first = Mp[arr[i].first];
        arr[i].second = Mp[arr[i].second];
    }
    for(ll i=0; i<q; i++)
        qu[i] = Mp[qu[i]];

    for(ll i=0; i<n; i++)
    {
        update(1,0,mx, arr[i].first, arr[i].second);
    }
    printf("Case %lld:\n",++cas);
    for(ll i=0; i<q; i++)
    {
        printf("%lld\n",query(1,0,mx,qu[i],qu[i],0));
    }
    }
}
