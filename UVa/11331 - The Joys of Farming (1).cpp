#include<bits/stdc++.h>
using namespace std;
pair <int,int> Pair[20010];
int vis[2010];
vector <int> G[2010];
int DP[2010][2010];
int pair_ind;
int B,C;
void dfs(int u, int next)
{
    if(vis[u]) return;
    if(next%2) Pair[pair_ind].first++;
    else Pair[pair_ind].second++;
    vis[u] = 1;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        dfs(v , next+1);
    }
}

int fun(int pos, int sum)
{
    if(pos==pair_ind)
    {
        if(sum==0) return DP[pos][sum] = 1;
        return DP[pos][sum] = 0;
    }
    if(DP[pos][sum]!=-1) return DP[pos][sum];
    int a = 0, b = 0;
    if(sum-Pair[pos].first>=0) a = fun(pos+1,sum-Pair[pos].first);
    if(sum-Pair[pos].second>=0) b = fun(pos+1,sum-Pair[pos].second);
    return DP[pos][sum] = (a || b);
}

int main()
{
    int TC;
    cin >> TC;
    while(TC--){
    for(int i=0; i<2010; i++) {G[i].clear();}
    for(int i=0; i<20010; i++) {Pair[i].first = Pair[i].second = 0;}

    memset(vis,0,sizeof(vis));
    memset(DP,-1,sizeof(DP));
    int n;
    scanf("%d %d",&B, &C);
    scanf("%d",&n);
    while(n--)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    pair_ind = 0;
    for(int i=1; i<=B+C; i++)
    {
        if(!vis[i])
        {
            dfs(i,1);
            pair_ind++;
        }
    }
//    for(int i=0; i<pair_ind; i++)
//    {
//        cout << Pair[i].first << " ";
//        cout << Pair[i].second << endl;
//    }
    if(fun(0,B))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    }
}
