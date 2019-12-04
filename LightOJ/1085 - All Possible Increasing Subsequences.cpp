#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100010
ll arr[mx], mk[mx];
ll tree[mx*4];
ll Mod = 1000000007;
void update(ll node, ll b, ll e, ll i, ll j, ll val)
{
    if(e<i || b>j) return;
    if(b>=i && e<=j)
    {
        tree[node] = (tree[node]+val)%Mod;
        return;
    }
    ll mid = (b+e)/2;
    ll L = node*2;
    ll R = L+1;
    update(L, b,mid,i,j,val);
    update(R, mid+1,e ,i, j, val);
    tree[node] = (tree[L] + tree[R])%Mod;
}
ll query(ll node, ll b, ll e, ll i, ll j)
{
    if(b>e) return 0;
    if(e<i || b>j) return 0;
    if(b>=i && e<=j)
    {
        return tree[node];
    }

    ll mid = (b+e)/2;
    ll L = node*2;
    ll R = L+1;

    ll ret1 = query(L,b,mid, i,j);
    ll ret2 = query(R,mid+1,e,i,j);
    return (ret1+ret2)%Mod;
}
int main()
{
    ll TC,cas=0;
    scanf("%lld",&TC);
    while(TC--)
    {
        memset(tree,0,sizeof(tree));
        ll n;
        scanf("%lld",&n);
        set<ll>Set;
        set<ll> :: iterator it;
        for(ll i=0; i<n; i++)
        {
            scanf("%lld",&arr[i]);
            Set.insert(arr[i]);
        }
        map<ll,ll>Mp;
        ll idx=1;
        for(it = Set.begin(); it!= Set.end(); it++)
        {
            Mp[*it] = idx++;
        }
        for(ll i=0; i<n; i++)
        {
            arr[i] = Mp[arr[i]];
//            cout << arr[i] << " ";
        }
        for(ll i=0; i<n; i++)
        {
             ll val = query(1,0,n,0,arr[i]-1) + 1;
             update(1,0,n,arr[i],arr[i],val);
            // then update arr[i] by val+1
        }
        printf("Case %lld: %lld\n",++cas,query(1,0,n,0,n));
    }
}
