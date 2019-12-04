#include<bits/stdc++.h>
#define MAX 100005
#define ll long long
using namespace std;
ll arr[MAX];
map <ll,ll> MAP;
struct frequency
{
    ll val;
} tree[MAX*4];
void reset(ll n)
{
    n = n*4;
    for(ll i=0; i<n; i++)
    {
        tree[i].val = 0;
    }
    memset(arr,0,sizeof(arr));
    MAP.clear();
}
void init(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node].val = MAP[arr[b]];
        return;
    }
    ll Left=node*2;
    ll Right=node*2+1;
    ll mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node].val=max(tree[Left].val,tree[Right].val);
}

ll query(ll node,ll b,ll e,ll i,ll j)
{
    if(i>e||j<b) return -1;
    if(b>=i&&e<=j) return tree[node].val;
    ll Left=node*2;
    ll Right=node*2+1;
    ll mid=(b+e)/2;
    ll p1=query(Left,b,mid,i,j);
    ll p2=query(Right,mid+1,e,i,j);
    return max(p1,p2);
}

int main()
{
    ll n,q;
    //freopen("out.txt", "w", stdout);
    while(scanf("%lld",&n) ==1)
    {
        if(!n)
        {
            break;
        }
        scanf("%lld",&q);
        reset(n);
        for(ll b=1; b<=n; b++)
        {
            scanf("%lld",&arr[b]);
            MAP[arr[b]]++;
        }

        init(1,1,n);
        for(ll b=1; b<=q; b++)
        {
            ll i,j;
            scanf("%lld %lld",&i,&j);
            if(arr[i] == arr[j])
            {
                printf("%lld\n", j-i+1);
            }
            else
            {
                ll v1 = 0;
                while(i < j && arr[i+1] == arr[i])
                {
                    i++;
                    v1++;
                }
                 v1++;
                ll v2 = 0;
                while(i < j && arr[j-1] == arr[j])
                {
                    v2++;
                    j--;
                }
                i++;j--;
                v2++;
                ll mxx = max(v1,v2);
                //printf("i = %lld -- j = %lld -- v1 = %lld -- v2 = %lld\n",i,j, v1, v2);
                ll mx = query(1,1,n,i,j);
                mx = max(mxx,mx);
                cout << mx << endl;
            }
        }
    }
    return 0;
}
