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
bool pos;
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
            if(cnt == n-1){
                pos = 1;
                break;
            }
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
    pos = 0;
    map<string, int> Map;
    string s1[51];
    string s2[51];
    int ww[51];
    int m,n=1;
    sf(m);
    FOR(i,0,m)
    {
        cin >> s1[i] >> s2[i] >> ww[i];
        if(Map.count(s1[i])==0)
        {
            Map[s1[i]] = n++;
        }
        if(Map.count(s2[i])==0)
        {
            Map[s2[i]] = n++;
        }
    }
    n--;
    for(int i=0; i<m; i++)
    {
        edge now;
        now.u = Map[s1[i]];
        now.v = Map[s2[i]];
        now.w = ww[i];
//        printf("%d %d %d\n",now.u, now.v, now.w);
        e.pb(now);
    }
    int best = best_mst(n);
//    cout <<"n = " << n << endl;
//    printf("best = %d ... worst = %d\n",best, worst);
    if(pos) printf("Case %d: %d\n",++ind, best);
    else printf("Case %d: Impossible\n",++ind);
    }
}
