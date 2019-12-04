/// AC in (0.396 sec)
#include<bits/stdc++.h>
using namespace std;
#define mx 10010
struct st
{
    int v;
    int cst;
    bool isp;

    st(int _v, int _cst, bool _isp)
    {
        v = _v, cst = _cst, isp = _isp;
    }
};

struct node
{
    int v;
    int cst;
    int used;

    node(int _v, int _c, int _u)
    {
        v = _v, cst = _c, used = _u;
    }

    bool operator<(node ob) const
    {
        return cst > ob.cst;
    }
};
vector<st> G[mx];

int dijkstra(int n, int d)
{
    priority_queue<node> q;
    int dist[d+1][n];

    memset(dist, 1, sizeof(dist));

    q.push(node(0, 0, 0));
    dist[0][0] = 0;

    int u, v, cnt, cst;

    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        u = top.v;
//        cout << u << endl;

        if(u == n-1) return top.cst;

        for(int i = 0; i < G[u].size(); ++i)
        {
            v = G[u][i].v;
            cnt = top.used + ((G[u][i].isp)? 1 : 0);
            cst = top.cst + G[u][i].cst;

            if(cnt <= d && cst < dist[cnt][v])
            {
                dist[cnt][v] = cst;
                q.push(node(v, cst, cnt));
            }
        }
    }

    return -1;
}
int main()
{
    int t,idx=0;
    scanf("%d",&t);
    while(t--)
    {
        int n, m, k, d;
        scanf("%d %d %d %d",&n,&m,&k,&d);
        int u, v, w;
        while(m--)
        {
            scanf("%d %d %d",&u,&v,&w);
            G[u].push_back(st(v, w, false));
        }
        while(k--)
        {
            scanf("%d %d %d",&u,&v,&w);
            G[u].push_back(st(v, w, true));
        }
        int ans = dijkstra(n, d);
        printf("Case %d: ",++idx);
        if(ans == -1)
            printf("Impossible\n");
        else
            printf("%d\n",ans);
        for(int i=0; i<=n; i++) G[i].clear();
    }
    return 0;
}
