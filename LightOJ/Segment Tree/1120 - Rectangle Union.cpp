#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100010
ll tree[mx*4];
ll lazy[mx*4];
vector<ll> v;
struct st
{
    ll x,y1,y2,type;
    st() {}
    st (ll _x, ll _y1, ll _y2, ll _type)
    {
        x = _x;
        y1 = _y1;
        y2=_y2;
        type = _type;
    }
    bool operator <(const st&ob) const
    {
        return x < ob.x;
    }
};
vector<st> edge;

void reset()
{
    memset(tree,0,sizeof(tree));
    memset(lazy,0,sizeof(lazy));
    v.clear();
    edge.clear();
}
ll update(ll node, ll b, ll e, ll i, ll j, ll t)
{
    if(e<i || b>j)
    {
        if(lazy[node]) return v[e+1] - v[b];
        else return tree[node];
    }
    if(b>=i && e<=j)
    {
        lazy[node] += t;
        if(lazy[node]) return v[e+1] - v[b];
        else return tree[node];
    }

    ll mid = (b+e)/2;
    ll L = node*2;
    ll R = L+1;

    ll ret1 = update(L, b, mid, i, j, t);
    ll ret2 = update(R, mid+1,e, i, j, t);

    tree[node] = ret1 + ret2;

    if(lazy[node]) return v[e+1] - v[b];
    else return tree[node];


}

int main()
{
    ll TC, cas=0;
    scanf("%lld",&TC);
    while(TC--)
    {
        reset();
        ll n;
        scanf("%lld",&n);
        set<ll>Set;
        set<ll> :: iterator it;
        for(ll i=0; i<n; i++)
        {
            ll x1, x2, y1, y2;
            scanf("%lld %lld %lld %lld",&x1, &y1, &x2, &y2);
            Set.insert(y1);
            Set.insert(y2);

            edge.push_back ( st (x1, y1, y2, 1));
            edge.push_back ( st (x2, y1, y2, -1));
        }
        for(it = Set.begin(); it!= Set.end(); it++) v.push_back(*it);

        sort(edge.begin(), edge.end());

        for(ll i=0; i<edge.size(); i++)
        {
            edge[i].y1 = lower_bound(v.begin(), v.end(), edge[i].y1) - v.begin();
            edge[i].y2 = lower_bound(v.begin(), v.end(), edge[i].y2) - v.begin() - 1;
        }
        ll nn= v.size()-1;
        ll ans = 0LL;
        for(ll i=0; i<edge.size()-1; i++)
        {
           update(1, 0, nn, edge[i].y1, edge[i].y2, edge[i].type);
           ans += tree[1] * (edge[i+1].x - edge[i].x);
        }
        printf("Case %lld: %lld\n",++cas,ans);
    }
}
