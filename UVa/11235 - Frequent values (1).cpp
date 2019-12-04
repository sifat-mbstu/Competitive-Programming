#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define total_overlap(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define no_overlap(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW

#define mx 210000
ll arr[mx];
ll fre[mx];
ll tree[mx*4];

void build(ll lo, ll hi, ll pos)
{
    if(lo > hi) return;
    if(lo == hi)
    {
        tree[pos] = fre[arr[lo]];
        return;
    }
    ll mid = (hi+lo)/2;
    build(lo, mid, pos*2);
    build(mid+1, hi, pos*2+1);
    tree[pos] = max(tree[pos*2], tree[pos*2+1]);
}
ll query(ll qlo, ll qhi, ll lo, ll hi, ll pos)
{
    if(no_overlap(qlo, qhi, lo, hi))
    {
        return -1;
    }
    if(total_overlap(qlo, qhi, lo, hi))
    {
        return tree[pos];
    }
    ll mid = (lo+hi)/2;
    ll a = query(qlo, qhi, lo, mid, pos*2);
    ll b = query(qlo, qhi, mid+1, hi, pos*2+1);
    return max(a,b);
}
int main()
{
    ll n,m;
    while(scanf("%lld",&n)==1)
    {
        if(!n) break;
        memset(tree, 0, sizeof(tree));
        memset(arr, 0, sizeof(arr));
        memset(fre, 0, sizeof(fre));
        scanf("%lld",&m);
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&arr[i]);
            arr[i] += 100001;
            fre[arr[i]]++;
        }
        build(1,n, 1);
        ll a,b;
        ll ans = 1;
        while(m--)
        {

            scanf("%lld %lld",&a,&b);
//            a--;b--;
            if(arr[a] == arr[b])
            {
                ans = b-a+1;
            }
            else{
            ll f1=1, f2 = 1;
            while(a < b && arr[a] == arr[a+1])
            {
                a++;
                f1++;
            }
            while(a < b && arr[b] == arr[b-1])
            {
                b--;
                f2++;
            }
            a++;b--;
            ans = query(a,b,1,n,1);
            ll mxx = max(f1,f2);
            ans = max(mxx, ans);
            }
            printf("%lld\n",ans);
        }
    }

}
