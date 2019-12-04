#include<bits/stdc++.h>
using namespace std;
#define mx 1001
#define inf INT_MAX/3

int D[mx], cost[mx][mx];
vector <int> G[mx];
void dijkastra(int source)
{
    priority_queue <int> Q;
    Q.push(source);
    D[source] = 0;
    while(!Q.empty())
    {
        int u = Q.top();
        Q.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i];
            if((D[u]+ cost[u][v]) < D[v])
            {
                D[v] = D[u] + cost[u][v];
                Q.push(v);
            }
        }
    }
}

int main()
{
    int TC;
    int ind = 0;
    scanf("%d",&TC);
    while(TC--){
    int i, x, y, n, m, n1, n2, c;
    for(i=0; i<mx; i++) D[i] = inf;
    for(int i=0; i<mx; i++)
    {
        G[i].clear();
        for(int j=0; j<mx; j++)
        {
            cost[i][j] = inf;
        }
    }
    scanf("%d %d",&n,&m);
    for(i=0; i<m; i++)
    {
        scanf("%d %d %d",&x, &y, &c);
        G[x].push_back(y);
        G[y].push_back(x);
        cost[x][y] = min(c,cost[x][y]);
        cost[y][x] = min(c,cost[y][x]);
    }
    dijkastra(1);
    if(D[n]==inf)printf("Case %d: Impossible\n",++ind);
    else{printf("Case %d: %d\n",++ind,D[n]);}
    }
}
/**
    Sample from Shafayet's Blog

    4 4
    1 3 5
    1 2 2
    2 3 1
    3 4 3
    now enter n1 and n2 as your khayesh
*/

