#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define mp make_pair
#define mx 30010
int vis[mx];
vi G[mx];
map<pii, int> cost;
int Max = 0;
int Fin;
void dfs(int src, int w)
{
//    printf("src = %d... w=%d",src,w);
    if(Max < w){Max = w; Fin = src;}
//    Max = max(Max, w);
    vis[src] = 1;
    for(int i=0; i<G[src].size(); i++)
    {
        int v = G[src][i];
        if(!vis[v])
        {
//            cout << cost[mp(src,v)] << endl;
            dfs(v,w+cost[mp(src,v)]);
        }
    }
}

int main()
{
    int TC, ind=0;
    cin >> TC;
    while(TC--){
    for(int i=0; i<mx; i++)
    {
        G[i].clear();
    }
    cost.clear();
    memset(vis,0,sizeof(vis));
    Max = 0;
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++)
    {
        int u, v, w;
        scanf("%d %d %d",&u, &v, &w);
        G[u].push_back(v);
        G[v].push_back(u);
        cost[mp(u,v)] = w;
        cost[mp(v,u)] = w;
    }
    dfs(0,0);
    memset(vis,0,sizeof(vis));
    dfs(Fin, 0);
    printf("Case %d: %d\n",++ind,Max);
    }
//    cout << Max << endl;
}
