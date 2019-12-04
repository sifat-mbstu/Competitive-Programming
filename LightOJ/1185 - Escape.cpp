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
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
#define mx  1010
vi G[mx];
int cnt;
int vis[mx];
bool t = 0;
void dfs(int u, int state)
{
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if(vis[v] == !state)
        {
            continue;
        }
        t = 1;
        if(vis[v]!=0)
        {
            vis[v] = !state;
            if(!vis[v]) cnt++;
        }
        dfs(v, !state);
    }
}

int main()
{
    int TC, ind = 0;
    sf(TC);
    while(TC--)
    {
        int n,m;
        FOR(i,0,mx)
        {
            G[i].clear();
            vis[i] = -1;
        }
        cnt = 0;
        t = 0;
        sf2(n,m);
        for(int i=0; i<m; i++)
        {
            int u,v;
            sf2(u,v);
            G[u].pb(v);
            G[v].pb(u);
        }
        vis[1] = 0;
        dfs(1,0);
        if(t) cnt++;

        printf("Case %d: %d\n",++ind, cnt);
    }
}

