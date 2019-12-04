#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define SQ(n) (n*n)
#define ll long long
#define llu unsigned long long

#define pi acos(-1.0)

#define all(a) a.begin(),a.end()
#define _max(a,b,c) Max(a,Max(b,c))
#define _min(a,b,c) Min(a,Min(b,c))

#define FOR(i,a,b) for(int i=a;i<b; i++)

#define MEM(a,val) memset(a,val,sizeof(a))

#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d%d",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

#define tover(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define nover(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW

#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
#define MOD 1000000007
#define inf INT_MAX/3
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
#define pii pair<int,int>
#define mx 100010
ll arr[mx],trmx[mx*4], trmn[mx*4];
void build(ll node, ll b, ll e)
{
    if(b==e)
    {
        trmn[node] = arr[b];
        trmx[node] = arr[b];
        return;
    }
    ll mid = (b+e)/2;
    ll l = node*2;
    ll r = node*2+1;
    build(l,b,mid);
    build(r,mid+1,e);
    trmx[node] = max(trmx[l],trmx[r]);
    trmn[node] = min(trmn[l],trmn[r]);
}
ll qmax(ll node, ll b, ll e, ll qb, ll qe)
{
    if(nover(qb,qe,b,e)) return 0;
    if(tover(qb,qe,b,e)) return trmx[node];
    ll mid=(b+e)/2;
    ll aa = qmax(node*2,b,mid,qb,qe);
    ll bb = qmax(node*2+1,mid+1,e,qb,qe);
    return max(aa,bb);
}
ll qmin(ll node, ll b, ll e, ll qb, ll qe)
{
    if(nover(qb,qe,b,e)) return inf;
    if(tover(qb,qe,b,e)) return trmn[node];
    ll mid=(b+e)/2;
    ll aa = qmin(node*2,b,mid,qb,qe);
    ll bb = qmin(node*2+1,mid+1,e,qb,qe);
    return min(aa,bb);
}
int main()
{
    ll idx= 0;
    ll TC;
    scanf("%lld",&TC);
    while(TC--){
    ll n,d;
    memset(trmx,0,sizeof(trmx));
    memset(trmn,0,sizeof(trmn));
    scanf("%lld %lld",&n, &d);
    d--;
    for(ll i=0; i<n; i++)
    {
        scanf("%lld",&arr[i]);
    }
    build(1,0,n-1);
    ll Max = 0;
    for(ll i=d; i<n; i++)
    {
        ll dif = abs(qmax(1,0,n-1,i-d,i)-qmin(1,0,n-1,i-d,i));
//        cout << "Max = " << qmax(1,0,n-1,i-d,i) << endl;
//        cout << "Min = "<< qmin(1,0,n-1,i-d,i) << endl;
        Max = max(Max,dif);
    }
    printf("Case %lld: %lld\n",++idx,Max);
    }
}
