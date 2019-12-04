#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define si stack <int>
#define pb push_back
#define mx 20001
vi G[mx], R[mx], Ans[mx], Dir[mx];
int col[mx], indeg[mx], outdeg[mx];
si st;
int vis[mx], vis2[mx];
void ini()
{
    for(int i=0; i<mx; i++)
    {
        G[i].clear();
        R[i].clear();
        Ans[i].clear();
        Dir[i].clear();
    }
    memset(vis, 0, sizeof(vis));
    memset(vis2, 0, sizeof(vis2));
    memset(indeg, 0, sizeof(indeg));
    memset(outdeg, 0, sizeof(outdeg));
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
    vis2[u] = 1;
    for(int i=0; i<R[u].size(); i++)
    {
        int v = R[u][i];
        if(!vis2[v]) {dfs2(v,ii); }
    }
    Ans[ii].pb(u);

}
int main()
{
    int TC,IND=0;
    cin >> TC;
    while(TC--){
    ini();
    int node, edge;
    scanf("%d %d",&node, &edge);
    memset(vis,0,sizeof(vis));
    memset(vis2,0,sizeof(vis2));
    for(int i=0; i<edge; i++)
    {
        int u,v;
        scanf("%d %d",&u, &v);
        G[u].pb(v);
        R[v].pb(u);
    }
    for(int i=1; i<=node; i++)
    {
        if(!vis[i]){dfs1(i);}
    }
    memset(vis,0,sizeof(vis));

    int ii = 0;
    while(!st.empty())
    {
        int a = st.top();
        st.pop();
        if(!vis2[a])
        {
            dfs2(a, ++ii);
        }
    }
    memset(col,0,sizeof(col));
    for(int i=1; i<=ii; i++)
    {
        for(int j=0; j<Ans[i].size(); j++)
        {
            col[Ans[i][j]] = i;
        }
    }
    for(int i=1; i<=node; i++)
    {
//        cout <<"i = " << i << "col = " <<  col[i] << endl;
        for(int j=0; j<G[i].size(); j++)
        {
            int v = G[i][j];
            if(col[i] != col[v])
            {
                Dir[col[i]].pb(col[v]);
            }
        }
    }
//    cout << "scc => " << endl;
    for(int i=1; i<=ii; i++)
    {
//        cout << i << " -> ";
        for(int j=0; j<Dir[i].size(); j++)
        {
            outdeg[i]++;
            indeg[Dir[i][j]]++;
//            cout << Dir[i][j] << " " ;
        }
//        cout << endl;
    }
    int a=0, b=0;
    for(int i=1; i<=ii; i++)
    {
//        cout << i << " ------> " << indeg[i] << " " << outdeg[i] << endl;
        if(!indeg[i]) a++;
        if(!outdeg[i]) b++;
    }
//    cout <<" a  = " <<  a << endl;
//    cout <<" b  = " <<  b << endl;
    int Fin_ans = max(a,b);

    if(ii==1) Fin_ans = 0;
    printf("Case %d: %d\n",++IND,Fin_ans);
//    cout << Fin_ans << endl;
    }
}
