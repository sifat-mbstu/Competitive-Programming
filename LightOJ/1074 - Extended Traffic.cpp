#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX/3
#define mx 220
struct st
{
    int u,v,w;
    st(int _u,int _v, int _cost)
    {
        u = _u;
        v = _v;
        w = _cost;
    }
};

vector <st> node;
bool yes = 1;
int dis[mx], cst[mx];

void bellman(int n, int e)
{
    for(int i=0; i<mx; i++)
        dis[i] = inf;

    dis[0] = 0;
    bool update;
    for(int step=1; step<=n+100; step++)
    {
        for(int i=0; i<e; i++)
        {
            int u = node[i].u;
            int v = node[i].v;
            int w = node[i].w;
            update = 0;
            if(dis[v]>dis[u]+w && dis[u]!=inf)
            {
                update = 1;
                dis[v] = dis[u]+w;
            }
        }
    }
}

int main()
{
    int TC, idx = 0;
    scanf("%d",&TC);
    while(TC--)
    {
        node.clear();
        yes = 1;
        int n,m;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&cst[i]);
        printf("Case %d:\n",++idx);
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            scanf("%d %d", &u, &v);
            u--; v--;
            w  = (cst[v]-cst[u]) * (cst[v]-cst[u]) * (cst[v]-cst[u]);
            node.push_back(st(u,v,w));
        }
        bellman(n,m);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int vv;
            scanf("%d",&vv);
            vv--;
            if(dis[vv]>=inf || dis[vv]<3)
            {
                printf("?\n");
            }
            else
                printf("%d\n",dis[vv]);
        }
    }
}
