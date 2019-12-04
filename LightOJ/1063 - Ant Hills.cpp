#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define MAXX 100007
vi adj[MAXX];
int disc[MAXX];
int low[MAXX], AP[MAXX],vis[MAXX],parent[MAXX];
int tim;
int cnt = 0;
void ini()
{
    int i;
    for(i =0; i<MAXX; i++)
    {
        vis[i]=AP[i]=false;   //Initializing AP and vis array as false
        parent[i]=-1;         // Initializing parent of each vertex to -1
        adj[i].clear();       // clearing the adjacency list.
        low[i]=0;
    }
    tim=0; // initializing tim to 0
    cnt=0; // initializing tim to 0
}

void dfs(int u)
{
//    printf("u = %d\n",u);
    vis[u]=true;
    int i;

    low[u] = disc[u] = ++tim;

    int child=0;
    for(i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(vis[v]==false)
        {
            child++;
            parent[v]=u;
            dfs(v);
//            printf("after v = %d\n",v);
            low[u]=min(low[u],low[v]);
//            printf("First---//// low[%d] = %d\n\n",u,low[u]);
            if( (parent[u]!=-1) and ( low[v]>=disc[u] ) )
            {
//                cnt++;
                AP[u]=true;
//                printf("AP = %d\n",u);
            }
            if( (parent[u]==-1) and (child>1))
            {
//                cnt++;
                AP[u]=true;
//                printf("AP = %d\n",u);
            }
        }

        else if(v!=parent[u])
        {
            low[u] = min(low[u],disc[v]);
//            printf("---//// low[%d] = %d\n\n",u,low[u]);
        }
    }

}
int main()
{
    int TC,ind=0;
    cin >> TC;
    while(TC--){
    ini();
    int node, edge;
    cin >> node >> edge;
    for(int i=0; i<edge; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    for(int i=1; i<=node ;i++)
    {

       if(AP[i]) cnt++;//printf("AP %d = %d\n",i, disc[i]);
    }
    printf("Case %d: %d\n",++ind,cnt);
//    cout << cnt << endl;
    }
//    for(int i=1; i<=node ;i++)
//    {
//       printf("lo %d = %d\n",i, low[i]);
//    }
//    for(int i=1; i<=node; i++)
//    {
//        printf("**par[%d]= %d\n",i,parent[i]);
//    }
//    for(int i=1; i<=node; i++)
//    {
//        cout << i << ": ";
//        for(int j=0; j<adj[i].size(); j++)
//        {
//            int v = adj[i][j];
//            printf(" %d", v);
//        }
//        cout << endl;
//    }

}
/***
A Sample Input From Shafayet Vai's Blog

7 6

1 2
1 3
3 4
4 5
4 6
3 7
*/
