#include<bits/stdc++.h>
using namespace std;
int Mat[500][500], taken[500], total, COST ;
vector <int> G[500];
int dfs(int n)
{
    if(!taken[n]) taken[n] = 1;
    for(int i=0; i< G[n].size(); i++)
    {
        int m = G[n][i];
        if(taken[m] == 0){
        COST += Mat[n][m];
        dfs(m);
        }
    }
}
int main()
{
    int TC, x, y, cost, total, Edge, Node;
    cin >> TC;
    for(int z = 1; z<=TC; z++){
    for(int i=0; i<500; i++) G[i].clear();
    memset(Mat, 0 ,sizeof(Mat));
    memset(taken, 0 ,sizeof(taken));
    cin >> Edge;
    total = 0;
    for(int i=0; i<Edge; i++)
    {
        cin >> x >> y >> cost;
        G[x].push_back(y);
        G[y].push_back(x);
        Mat[x][y] = 0;
        Mat[y][x] = cost;
        total += cost;
    }
    COST = 0;
    dfs(1);
    COST += Mat[ G [1][1] ] [1];
    //cout << COST << endl;
    printf("Case %d: %d\n",z,min(COST, total - COST) );
    }
}
