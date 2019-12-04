#include<bits/stdc++.h>
using namespace std;
#define inf 500000
#define mx 300
int cst[mx][mx];
int cap[mx];
int vis[300];
int par[300];
vector<int>G[300];
bool bfs(int src, int sink)
{
    memset( vis,0,sizeof(vis)  );
    memset( par,-1,sizeof(par) );

    queue<int>Q;
    Q.push(src);
    vis[src] = 1;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i];
            if(!vis[v] && cst[u][v]>0)
            {
                vis[v] = 1;
                par[v] = u;
                Q.push(v);
                if(v==sink) return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int TC,idx = 0;
    scanf("%d",&TC);
    while(TC--)
    {
        int n,m;
        scanf("%d",&n);
        memset(cst,0,sizeof(cst));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&cap[i]);
            G[i].push_back(n+i);
            G[n+i].push_back(i);
            cst[i][n+i] += cap[i];
        }
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            int u,v,c;
            scanf("%d %d %d",&u, &v, &c);
            G[n+u].push_back(v);
            G[v].push_back(n+u);

            cst[n+u][v] += c;
        }
        int B,D;
        scanf("%d %d",&B, &D);
        int src= 0, sink = 2*n+1;
        for(int i=0; i<B; i++)
        {
            int val;
            scanf("%d",&val);
            G[0].push_back(val);
            G[val].push_back(0);

            cst[0][val] = inf;
        }
        for(int i=0; i<D; i++)
        {
            int val;
            scanf("%d",&val);
            val += n;
            G[sink].push_back(val);
            G[val].push_back(sink);

            cst[val][sink] = inf;
        }
        int flow=0;
        while(1)
        {
           bool now = bfs(src, sink);
            if(par[sink]==-1) break;
            vector<int>path;
            path.push_back(sink);

            int des = sink;
            while(par[des]!=-1)
            {
                path.push_back(par[des]);
                des = par[des];
            }
            int Min = inf;
            for(int i=path.size()-1; i>0; i--)
            {
                int u = path[i];
                int v = path[i-1];
                Min = min(Min,cst[u][v]);
            }

            for(int i=path.size()-1; i>0; i--)
            {
                int u = path[i];
                int v = path[i-1];
                cst[u][v] -= Min;
                cst[v][u] += Min;
            }
            if(now) flow += Min;
        }
        printf("Case %d: %d\n",++idx,flow);
        for(int i=0;i<=mx; i++)G[i].clear();
    }

}
