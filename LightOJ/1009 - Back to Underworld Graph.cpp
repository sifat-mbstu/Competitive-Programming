#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX/3
#define mx 1000000
vector < int> G[100010];
int level[mx];// = {inf};
int even, odd;
void reset()
{
    for(int i=0; i<100010; i++)
    {
        G[i].clear();
      //  level[i] = inf;
    }
}
void BFS(int source)
{
    queue <int> Q;
    odd = even = 0;
    Q.push(source);
    level[source] = 0;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if(level[u]%2) odd++;
        else even++;
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i];
            if(level[v] == inf)
            {
                level[v] = level[u] + 1;
                Q.push(v);

                //cout << "level[" <<v << "] = " << level[v] << endl;
            }
        }
//        cout << endl;
    }
}
int main()
{
    int ind=0, TC;
    cin >> TC;
    while(TC--){
    for(int i=0; i<mx; i++) level[i] = inf;

    int node, edge, u , v, source,n1,n2 ;
    cin >> edge ;
    cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    n1 = u;
    for(int i=1; i<edge; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    BFS(n1);
    printf("Case %d: %d\n",++ind, max(odd,even));
    reset();
    }
}
