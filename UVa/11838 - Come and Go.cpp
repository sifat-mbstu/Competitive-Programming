///Done Successfully
///Kosaraju's Algorithm
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define si stack <int>
#define pb push_back
#define mx 20001
vi G[mx], R[mx], Ans[mx];
si st;
int vis[mx];
void ini()
{
    for(int i=0; i<mx; i++)
    {
        vis[i] = 0;
        G[i].clear();
        R[i].clear();
        Ans[i].clear();
    }
}
int dfs1(int u)
{
    vis[u] = 1;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if(!vis[v]) dfs1(v);
    }
    st.push(u);
}
void dfs2(int u, int ii)
{
    vis[u] = 1;
    for(int i=0; i<R[u].size(); i++)
    {
        int v = R[u][i];
        if(!vis[v]) dfs2(v,ii);
    }
    Ans[ii].pb(u);
}
int main()
{
    int node, edge;
    while(scanf("%d %d",&node, &edge)==2){
    if(!node && !edge){break;}
    ini();
    for(int i=0; i<edge; i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u, &v, &w);
        G[u].pb(v);
        R[v].pb(u);
        if(w==2)
        {
            R[u].pb(v);
            G[v].pb(u);
        }
    }
    for(int i=1; i<=node; i++)
    {
        if(!vis[i]) dfs1(i);
    }
    memset(vis,0,sizeof(vis));
    int ii = 0;
    while(!st.empty())
    {
        int a = st.top();
//        cout <<"top " <<  a << endl;
        st.pop();
        if(!vis[a])
        {
            dfs2(a, ii++);
        }
    }
    if(ii == 1)
    {
        cout << ii << endl;
    }
    else
    {
        cout << 0 << endl;
    }
//    for(int i=0; i<ii; i++)
//    {
////        printf("index = %d : ", i+1 );
//        for(int j=0; j<Ans[i].size(); j++)
//        {
//            cout << Ans[i][j] << " ";
//        }
//        cout << endl;
//    }
    }
}
