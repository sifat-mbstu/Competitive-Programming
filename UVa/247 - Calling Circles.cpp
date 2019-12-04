///Done Successfully
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define msi map<string, int>
#define mii map<int, int>
#define si stack <int>
#define pb push_back
#define mx 30
vi G[mx], R[mx], Ans[mx];
set <string> Set;
msi Map;
string s[mx];
si st;
int vis[mx];
void ini()
{
    Map.clear();
    Set.clear();
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
//    cout <<"ii " << ii << endl;
    vis[u] = 1;
    for(int i=0; i<R[u].size(); i++)
    {
        int v = R[u][i];
        if(!vis[v]) dfs2(v,ii);
    }
    Ans[ii].pb(u);
//    cout << "ii - " << ii << " u = " << u << endl;
}
int main()
{
    int node, edge, ind=0;
    while(scanf("%d %d",&node, &edge)==2){
    if(!node && !edge) break;
    ini();
    int indexx = 0;
    for(int i=0; i<edge; i++)
    {
        string u,v;
        cin >> u >> v;
        if(!Set.count(u)){Set.insert(u);s[indexx] = u; Map[u]=indexx++;}
        if(!Set.count(v)){Set.insert(v);s[indexx] = v; Map[v]=indexx++;}
        G[Map[u]].pb(Map[v]);
        R[Map[v]].pb(Map[u]);
    }
    for(int i=0; i<node; i++)
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
            dfs2(a, ii);
            ii++;
        }
    }
    printf("Calling circles for data set %d:\n",++ind);
    for(int i=0; i<ii; i++)
    {
//        printf("index = %d : ", i );
        if(Ans[i].size()){cout << s[Ans[i][0]] ;}
        for(int j=1; j<Ans[i].size(); j++)
        {
            cout << ", " << s[Ans[i][j]] ;
        }
        cout << endl;
    }
    }
//    cout << "ans check " << Ans[0][0] << endl;

}
