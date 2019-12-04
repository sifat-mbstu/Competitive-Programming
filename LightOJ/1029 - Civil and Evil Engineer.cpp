///Accepted (0.084 Second)
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

#define total_overlap(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define no_overlap(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW

#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
#define MOD 1000000007
#define inf INT_MAX/3
#define mx 10100
struct edge{
    int u,v,w;
    bool operator < (const edge& p) const
    {
        return w<p.w;
    }
};
int pr[mx];
vector <edge> e;

int Find(int node)
{
    if(node == pr[node])
    {
        return node;
    }
    return Find(pr[node]);
}
int best_mst(int n)
{
    sort(e.begin(), e.end());
    for(int i=0; i<=n; i++)
    {
        pr[i] = i;
    }
    int cnt = 0, sum = 0;
    for(int i=0; i<e.size(); i++)
    {
        int u = Find(e[i].u);
        int v = Find(e[i].v);
        if(u!=v)
        {
            pr[u] = v;
            cnt++;
            sum += e[i].w;
            if(cnt == n)
                break;
        }
    }
    return sum;
}
int worst_mst(int n)
{
    for(int i=0; i<=n; i++)
    {
        pr[i] = i;
    }
    int cnt = 0, sum = 0;
    for(int i=e.size()-1; i>=0; i--)
    {
        int u = Find(e[i].u);
        int v = Find(e[i].v);
//        printf(" u = %d ,, v = %d\n\n",u,v);
//        cout << "e[i].u = " << e[i].u << "  e[i].v = " << e[i].v << endl;
        if(u!=v)
        {
            pr[u] = v;
            cnt++;
            sum += e[i].w;
            if(cnt == n)
                break;
        }
    }
    return sum;
}
int main()
{
    int TC, ind =0;
    cin >> TC;
    while(TC--){
    e.clear();
//    memset(pr,0,sizeof(pr));
    int n;
    sf(n);
    while(1)
    {
        int u,v,w;
        sf3(u,v,w);
        if(!u && !v && !w) break;
        edge now;
        now.u = u;
        now.v = v;
        now.w = w;
        e.pb(now);
    }
    int best = best_mst(n);
    int worst = worst_mst(n);
    int fin = best+worst;
//    printf("best = %d ... worst = %d\n",best, worst);
    if(fin%2==0) printf("Case %d: %d\n",++ind, fin/2);
    else
        printf("Case %d: %d/2\n",++ind,fin);
    }
}
