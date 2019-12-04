#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i,a,b) for(int i=a;i<b; i++)
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d%d",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

#define FO freopen("out.txt", "w", stdout)
#define mx 50010

struct edge
{
    int u,v,w;
    bool operator < (const edge& p) const
    {
        return w<p.w;
    }
};
int L[mx];
int P[mx][16];
int cst[mx][16];
pii T[mx];
vector<pii>g[mx];
int pr[mx];
vector <edge> e;


void reset()
{
    cst[0][0] = 0;
    P[0][0] = -1;
}

void dfs(int from,int u,int dep)
{
    L[u] = dep;
    T[u].ff = from;
    for(int i=0; i<(int)g[u].size(); i++)
    {
        int v = g[u][i].ff;
        if(L[v]==-1)
        {
            T[v].ss = g[u][i].ss;
            dfs(u,v,dep+1);
        }
    }
}

int lca_query(int N, int p, int q)
{
    int tmp, log=1, i;
    if (L[p] < L[q]) swap(p,q);
    if(L[p]>0)log = log2(L[p])+1;
    int Max = 0;
    for (i = log; i >= 0; i--)
    {
        if (L[p] - (1 << i) >= L[q])
        {
            Max = max(Max,cst[p][i]);
            p = P[p][i];
        }
    }
    if (p == q) return Max;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
        {
            Max = max(Max,cst[p][i]);
            Max = max(Max,cst[q][i]);
            p = P[p][i], q = P[q][i];
        }
    Max = max(Max,cst[p][0]);
    Max = max(Max,cst[q][0]);
    return Max;
}

void lca_init(int N)
{
//    memset (P,-1,sizeof(P));
    int i, j;
    for (i = 0; i < N; i++)
    {
        P[i][0] = T[i].ff;
        cst[i][0] = T[i].ss;
    }
    for (j = 1; 1 << j < N; j++)
    {
        for (i = 0; i < N; i++)
        {
            if (P[i][j - 1] != -1)
            {
                cst[i][j] = max(cst[i][j-1], cst[P[i][j - 1]][j-1]);
                P[i][j] = P[P[i][j - 1]][j - 1];
            }
        }
    }
}



int Find(int node)
{
    if(node == pr[node])
    {
        return node;
    }
    return pr[node] = Find(pr[node]);
}

int mst(int n)
{
    sort(e.begin(), e.end());
    for(int i=0; i<n; i++)
    {
        pr[i] = i;
    }
    int cnt = 0, sum = 0;
    int m = e.size();
    for(int i=0; i<m; i++)
    {
        int u = Find(e[i].u);
        int v = Find(e[i].v);
        if(u!=v)
        {
            pr[u] = v;
            cnt++;

            g[e[i].u].pb(mp(e[i].v,e[i].w));
            g[e[i].v].pb(mp(e[i].u,e[i].w));
            if(cnt == n-1)
                break;
        }
    }
    e.clear();
    return n-1;
}
int main()
{
    int TC,z=0;
    scanf("%d",&TC);
    while(TC--)
    {
        int n,m,i;
        sf2(n,m);
        for(int i=0; i<=n; i++) g[i].clear(),L[i]=-1;
        reset();
        FOR(i,1,m+1)
        {
            int u,v,w;
            sf3(u,v,w);
            edge now;
            now.u = u-1;
            now.v = v-1;
            now.w = w;
            e.pb(now);
        }
        m = mst(n);

        L[0] = 0;
        dfs(0, 0, 0);
        int q;
        lca_init(n);
        scanf("%d",&q);
        printf("Case %d:\n",++z);

        while(q--)
        {
            int a, b;
            scanf("%d %d",&a, &b);
            printf("%d\n", lca_query(n,a-1,b-1));
        }
    }
}
