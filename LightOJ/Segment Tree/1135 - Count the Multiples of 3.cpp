#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define total_overlap(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define no_overlap(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW
#define inf ll_MAX/3
#define mx 100010
ll arr[mx];
struct st
{
    ll one;
    ll two;
    ll zero;
} tree[mx*4];
ll lazy[mx*4];

void proc(ll node, ll idx)
{
    ll n1 = tree[node].one;
    ll n2 = tree[node].two;
    ll n0 = tree[node].zero;
    if(idx == 1)
    {
        tree[node].zero = n2;
        tree[node].one = n0;
        tree[node].two = n1;
    }
    else if(idx == 2)
    {
        tree[node].zero = n1;
        tree[node].two = n0;
        tree[node].one = n2;
    }
}

void build(ll node, ll b, ll e)
{
    if(b>e)
        return;
    if(b==e)
    {
        tree[node].zero = 1;
        return;
    }
    ll mid = (b+e)/2;
    ll L = node*2;
    ll R = L+1;

    build(L,b, mid);
    build(R,mid+1, e);

    tree[node].zero = tree[L].zero + tree[R].zero;
}
void update_lazy(ll node, ll b, ll e,ll i,ll j, ll val)
{
    ll mid = (b+e)/2;
    ll L = node*2;
    ll R = L+1;
    if(lazy[node])
    {
        lazy[node] = lazy[node]%3;
        if(e!=b)
        {
            lazy[L] += lazy[node];
            lazy[R] += lazy[node];
        }

        if(lazy[node]==1)
        {
            proc(node,1);
        }
        else if(lazy[node]==2)
        {
            proc(node,2);
        }
        lazy[node] = 0;
    }
    if(no_overlap(i, j, b, e))
        return;
    if(total_overlap(i, j, b, e))
    {
        lazy[node]++;
        lazy[node] = lazy[node] % 3;
        if(e!=b)
        {
            lazy[L] += lazy[node];
            lazy[R] += lazy[node];
        }
        if(lazy[node]==1)
        {
            proc(node,1);
        }
        else if(lazy[node]==2)
        {
            proc(node,2);
        }
        lazy[node] = 0;
        return;
    }
    update_lazy(L, b, mid, i, j,val);
    update_lazy(R, mid+1,e, i, j,val);

    tree[node].one = tree[L].one + tree[R].one;
    tree[node].two = tree[L].two + tree[R].two;
    tree[node].zero = tree[L].zero + tree[R].zero;
}

ll query(ll node, ll b, ll e, ll i, ll j)
{
    ll mid = (b+e)/2;
    ll L = 2*node;
    ll R = L+1;
    if(lazy[node])
    {
        lazy[node] = lazy[node]%3;
        if(b!=e)
        {
            lazy[L] += lazy[node];
            lazy[R] += lazy[node];
        }
        if(lazy[node]==1)
        {
            proc(node,1);
        }
        else if(lazy[node]==2)
        {
            proc(node,2);
        }
        lazy[node] = 0;
    }
    if(no_overlap(i, j, b, e))
    {
        return 0;
    }
    if(total_overlap(i, j, b, e))
    {
        return tree[node].zero;
    }
    ll ret1 = query(L, b, mid, i, j);
    ll ret2 = query(R, mid+1, e, i, j);
    return ret1+ret2;
}
int main()
{
    ll TC, ind = 0, n, q;
    scanf("%lld",&TC);
    while(TC--)
    {
        scanf("%lld %lld",&n,&q);
        for(int i=0; i<=n*4; i++)
        {
            tree[i].one =  tree[i].zero = tree[i].two = lazy[i] = 0;
        }
        build(1,0,n-1);
        printf("Case %lld:\n",++ind);
        while(q--)
        {
            ll choise;
            scanf("%lld",&choise);
            if(choise == 0)
            {
                ll a, b, val = 1;
                scanf("%lld %lld",&a, &b);
                update_lazy(1,0,n-1, a, b, val);
            }
            else
            {
                ll a, b;
                scanf("%lld %lld",&a, &b);
                printf("%lld\n",query(1, 0, n-1, a, b));
            }
        }
    }
}
