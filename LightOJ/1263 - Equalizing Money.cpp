#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mx 101000
bool yes = 1;
vector<int>G[mx];
int cst[mx],vis[mx];
int cnt = 0;
int dfs(int src)
{
    vis[src] = 1;
    int sum = 0;
    for(int i=0; i<G[src].size() ; i++)
    {
        int v = G[src][i];
        if(!vis[v]) {sum += cst[v]+dfs(v); cnt++;}

    }
    return sum;
}

int main()
{
    int idx = 0;
    int TC;
    scanf("%d",&TC);
    while(TC--){
    int n,m;
    scanf("%d %d",&n, &m);
    for(int i=0; i<mx; i++){G[i].clear();vis[i]=0;}
    yes = 1;
    int desired = 0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&cst[i]);
        desired += cst[i];
    }
    if(desired%n==0)
    {
        desired = desired/n;
    }
    else
    {
        yes = 0;
    }
    for(int i=0; i<m; i++)
    {
        int u,v;
        scanf("%d %d",&u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }
    for(int i=1; i<=n; i++)
    {
        if(!yes) break;
        if(!vis[i])
        {
            cnt = 1;
            int now = cst[i] + dfs(i);
            if(now%cnt) {yes = 0;}
            else
            {
                int d = now/cnt;
                if(d!=desired) {yes = 0;}
            }
        }
    }
    if(yes) printf("Case %d: Yes\n",++idx);
    else printf("Case %d: No\n",++idx);
    }
}
