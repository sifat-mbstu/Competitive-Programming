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
int Max1[mx], Max2[mx];
int Fin;
void dfs(int src, int w)
{
    if(Max < w)
    {
        Max = w;
        Fin = src;
    }
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
void dfs1(int src, int w)
{
    Max1[src] = w;
//    printf("src = %d .. w=%d\n",src,w);
    if(Max < w)
    {
        Max = w;
        Fin = src;
    }
//    Max = max(Max, w);
    vis[src] = 1;
    for(int i=0; i<G[src].size(); i++)
    {
        int v = G[src][i];
        if(!vis[v])
        {
//            cout << cost[mp(src,v)] << endl;

            dfs1(v,w+cost[mp(src,v)]);
        }
    }
}
void dfs2(int src, int w)
{
    Max2[src] = w;
//        printf("src = %d .. w=%d\n",src,w);
//    if(Max < w){Max = w; Fin = src;}
//    Max = max(Max, w);
    vis[src] = 1;
    for(int i=0; i<G[src].size(); i++)
    {
        int v = G[src][i];
        if(!vis[v])
        {
//            cout << cost[mp(src,v)] << endl;
            dfs2(v,w+cost[mp(src,v)]);
        }
    }
}
int main()
{
    int TC, ind=0;
    cin >> TC;
    while(TC--)
    {
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
        Max = 0;
        dfs1(Fin, 0);
        memset(vis,0,sizeof(vis));
        dfs2(Fin, 0);
        printf("Case %d:\n",++ind);
        for(int i=0; i<n; i++)
        {
            printf("%d\n",max(Max1[i],Max2[i]));
        }

    }
//    cout << Max << endl;
}
