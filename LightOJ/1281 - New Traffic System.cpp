#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX/3
#define pb push_back
#define mx 10010
#define pii pair<int,int>
#define piii pair<int,pii>
vector<piii> G[mx];
int n,m,k,d;
int dis[mx][20];
struct st
{
    int city,w,cnt;
    bool operator <(const st& p)const
    {
        return w<p.w;
    }
};
void dijkstra(int src)
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=15; j++)
        {
            dis[i][j] = inf;
        }
    }
    priority_queue<st>pq;
    st u;
    u.w = 0;
    u.city = src;
    u.cnt = 0;
    dis[src][0] = 0;
    pq.push(u);
    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();
        int DD = u.cnt;
        for(int i=0; i<G[u.city].size(); i++)
        {
            int v = G[u.city][i].second.first;
            int w = G[u.city][i].second.second;
            int ty = G[u.city][i].first;
            int Min = inf;
//            for(int j=0; j<=d; j++)
//            {
                int cur = dis[u.city][DD] + w;
                Min = min(Min,cur);
                int dd = DD + ty;
                if(cur<dis[v][dd])
                {
//                if(cur>=Min)
//                {
//                    continue;
//                }
                    dis[v][dd] = cur;
                    st fp;
                    fp.city = v;
                    fp.w = cur;
                    fp.cnt = dd;
                    pq.push(fp);
                }
//            }
        }
    }
    for(int i=0; i<=n; i++)
    {
        G[i].clear();
    }
}
int main()
{
    int TC,idx=0;
    scanf("%d",&TC);
    while(TC--)
    {
        scanf("%d %d %d %d",&n, &m, &k, &d);
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u, &v, &w);
            G[u].pb(piii(0,pii(v,w)));
//        G[v].pb(piii(0,pii(u,w)));
        }

        for(int i=0; i<k; i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u, &v, &w);
            G[u].pb(piii(1,pii(v,w)));
//        G[v].pb(piii(1,pii(u,w)));
        }

        dijkstra(0);
        int res = inf;
        for(int i=0; i<=d; i++)
            res = min(res, dis[n-1][i]);
//    cout << dis[n-1].first << endl;
        if(res>=inf)
            printf("Case %d: Impossible\n",++idx);
        else
            printf("Case %d: %d\n",++idx,res);

    }
}
