#include <bits/stdc++.h>
#define mx 505
#define inf INT_MAX/3
using namespace std;
#define vi vector<int>

#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d%d",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

int cst[mx][mx];
vi G[mx];
int dis[mx];

struct st
{
    int city, dist;
    bool operator < (const st &p) const
    {
        return p.dist < dist;
    }
};

void reset()
{
    for (int i = 0; i < mx; i++)
    {
        G[i].clear();
        dis[i] = inf;
        for (int j = 0; j < mx; j++)
        {
            cst[i][j] = inf;
        }
    }
}
void dijkstra(int src)
{
    int len;
    priority_queue <st> PQ;
    st u,v;
    u.city = src;
    u.dist = 0;
    dis[u.city] = 0;
    PQ.push(u);
    while(!PQ.empty())
    {
        u = PQ.top();
        PQ.pop();
        if(u.dist != dis[u.city])
            continue;

        len = G[u.city].size();
        for (int i = 0; i < len; i++)
        {
            v.city = G[u.city][i]; //u G connected with v..
            v.dist = max(u.dist, cst[u.city][v.city]);
            if(v.dist < dis[v.city])
            {
                dis[v.city] = v.dist;
                PQ.push(v);
            }
        }

    }
}

int main()
{
    int tc, cas = 0,n, m, p, q, w,src;
    sf(tc);
    while(tc--)
    {
        reset();
        sf2(n,m);
        for (int i = 0; i < m; i++)
        {
            sf3(p,q,w);
            if(w<cst[p][q])
            {
                cst[p][q] = w; cst[q][p] = w;
                G[p].push_back(q);
                G[q].push_back(p);
            }
        }
        sf(src);
        dijkstra(src);
        printf("Case %d:\n", ++cas);

        for (int i = 0; i < n; i++)
        {
            if(dis[i] == inf)
                printf("Impossible\n");
            else
                printf("%d\n", dis[i]);
        }
    }
    return 0;
}
