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
int expense;
int Find(int node)
{
    if(node == pr[node])
    {
        return node;
    }
    return Find(pr[node]);
}
pii mst(int n)
{
    sort(e.begin(), e.end());
    for(int i=1; i<=n; i++)
    {
        pr[i] = i;
    }
    int cnt = 0, sum = 0;
    int ex = 0;
    for(int i=0; i<e.size(); i++)
    {
        int u = Find(e[i].u);
        int v = Find(e[i].v);
        if(u!=v)
        {
            pr[u] = v;
            cnt++;
            if(e[i].w>=expense)
            {
                ex++;
                sum += expense;
            }
            else sum += e[i].w;
            if(cnt == n-1) break;
        }
    }
    sum += expense*(n-cnt);
    return mp(sum,n-cnt+ex);
}
int main()
{
    int TC, ind = 0;
    cin >> TC;
    while(TC--){
    memset(pr,0,sizeof(pr));
    e.clear();
    int n,m;
    sf3(n,m,expense);
    FOR(i,1,m+1)
    {
        int u,v,w;
        sf3(u,v,w);
        edge now;
        now.u = u;
        now.v = v;
        now.w = w;
        e.pb(now);
    }
    pii Fin = mst(n);
    printf("Case %d: ",++ind);
    cout << Fin.ff << " " << Fin.ss << endl;
    }
}
/**
    Sample Input:
    7 11
    1 2 7
    1 4 5
    2 3 8
    2 5 7
    4 5 15
    4 6 6
    2 4 9
    3 5 5
    5 6 8
    5 7 9
    6 7 11
*/

