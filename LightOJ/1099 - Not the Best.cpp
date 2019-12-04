#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mx 5001
#define inf INT_MAX/3

int D[2][mx];
vector <pii> G[mx];

struct st
{
    int city, dist;
    st(int x, int y)
    {
        city = x;
        dist = y;
    }
    bool operator < (const st &p) const
    {
        return p.dist < dist;
    }
};

void dijkastra(int source)
{
    priority_queue <st> Q;
    Q.push(st(source,0));
    D[0][source] = 0;
    while(!Q.empty())
    {
        st u = Q.top();
        Q.pop();
        for(int i=0; i<G[u.city].size(); i++)
        {
            int v = G[u.city][i].first;
            int cur = G[u.city][i].second;
            if((D[0][u.city]+ cur) < D[0][v])
            {
                D[1][v] = D[0][v];
                D[0][v] = D[0][u.city] + cur;
                Q.push(st(v,D[0][v]));
            }
            if(((D[0][u.city] + cur) < D[1][v]) && ((D[0][u.city]+ cur) > D[0][v]))
            {
                D[1][v] = D[0][u.city] + cur;
                Q.push(st(v,D[0][v]));
            }
            if(((D[1][u.city] + cur) < D[1][v]))
            {
                D[1][v] = D[1][u.city] + cur;
                Q.push(st(v,D[0][v]));
            }

        }
    }
}

int main()
{
    int TC;
    int ind = 0;
    scanf("%d",&TC);
    while(TC--)
    {
        int i, x, y, n, m, n1, n2, c;
        scanf("%d %d",&n,&m);
        for(int i=0; i<=n; i++)
        {
            D[0][i] = inf;
            D[1][i] = inf;
            G[i].clear();

        }
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&x, &y, &c);
            G[x].push_back(pii(y,c));
            G[y].push_back(pii(x,c));
        }
        dijkastra(1);
        printf("Case %d: %d\n",++ind,D[1][n]);
    }
}
