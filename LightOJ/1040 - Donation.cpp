///Accepted (0.024 Second)
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
struct edge
{
    int u,v,w;
    bool operator < (const edge& p) const
    {
        return w<p.w;
    }
};
int pr[mx];
vector <edge> e;
map<pii, int> Map;
bool pos;
int Find(int node)
{
    if(node == pr[node])
    {
        return node;
    }
    return Find(pr[node]);
}
int mst(int n)
{
    sort(e.begin(), e.end());
    for(int i=1; i<=n; i++)
    {
        pr[i] = i;
    }
//    for(int i=0; i<e.size(); i++)
//    {
//    printf("->%d %d %d\n",e[i].u,e[i].v,e[i].w);
//    }
    int cnt = 0, sum = 0;
    for(int i=0; i<e.size(); i++)
    {
        int u = Find(e[i].u);
        int v = Find(e[i].v);
        if(u!=v)
        {
            if(e[i].w==0)
            {
                continue;
            }
            pr[u] = v;
            cnt++;
            sum += e[i].w;
//            cout << "ami cnt bolchi = " << cnt << endl;
            if(cnt == n-1)
            {
                pos = 1;
                break;
            }
        }
    }
    return sum;
}
int main()
{
    int TC, ind = 0;
    cin >> TC;
    while(TC--)
    {
        Map.clear();
        e.clear();
        int n,m;
        sf(n);
        pos = 0;
        int sum = 0;
        FOR(i,1,n+1)
        {
            FOR(j,1,n+1)
            {
                int w;
                sf(w);
                Map[mp(i,j)] = w;
                edge now;
                now.u = i;
                now.v = j;
                now.w = w;
                e.pb(now);
                sum += w;
            }
        }
        int res = mst(n);
        if(n==1) printf("Case %d: %d\n",++ind,sum);
        else if(pos) printf("Case %d: %d\n",++ind,sum-res);
        else printf("Case %d: -1\n",++ind);
    }
}
