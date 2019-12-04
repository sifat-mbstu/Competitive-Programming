#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define inf INT_MAX/3
#define mx 1010
struct st
{
    int u,v,w;
    st(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};
vector<st> node;
vector<int> R[mx];
int vis[mx], res[mx], dis[mx];
void reset(int nn)
{
    node.clear();
    for(int i=0; i<nn; i++)
    {
        R[i].clear();
        res[i] = 0;
        dis[i] = inf;
        vis[i] = 0;
    }
}
void bellman(int src, int n, int e)
{
    for(int i=0; i<n; i++)
        dis[i] = inf;

    dis[src] = 0;
    for(int step = 0; step<n; step++)
    {
        for(int i=0; i<node.size(); i++)
        {
            int u = node[i].u;
            int v = node[i].v;
            int w = node[i].w;
            if(dis[u]==inf)
                continue;
            if(dis[v]>dis[u]+w)
            {
                dis[v] = dis[u]+w;
            }
        }
    }

    for(int step = 0; step<n; step++)
    {
        for(int i=0; i<node.size(); i++)
        {
            int u = node[i].u;
            int v = node[i].v;
            int w = node[i].w;
            if(dis[u]==inf)
                continue;
            if(dis[v]>dis[u]+w)
            {
                res[v] = 1;
                dis[v] = dis[u]+w;
            }

        }
    }
}
void dfs(int src)
{
    if(vis[src])
        return;
    vis[src] = 1;
    for(int i=0; i<R[src].size(); i++)
    {
        int v = R[src][i];
        if(!vis[v]) dfs(v);
    }
}
int main()
{
    int TC, idx = 0;
    scanf("%d",&TC);
    while(TC--)
    {
        int n,m;
        scanf("%d %d",&n, &m);
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u, &v, &w);
            R[v].pb(u);
            node.pb(st(v,u,w));
        }
        for(int i=0; i<n; i++)
        {
            R[n].pb(i);
            node.pb(st(n,i,1));
        }
        bellman(n,n,m);
        printf("Case %d:",++idx);
        bool yes = 0;
        for(int i=0; i<n; i++)
        {
            if(res[i]) dfs(i);
        }
        for(int i=0; i<n; i++)
        {
            if(vis[i])
            {
                printf(" %d",i);
                yes = 1;
            }
        }
        if(!yes)
            printf(" impossible");
        printf("\n");
        reset(n+1);
    } }
