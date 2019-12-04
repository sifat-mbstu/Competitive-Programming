//DONE
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define inf INT_MAX/3
int vis[10010], dis[10010];
vector<pii>G[10100];
priority_queue<pii> pq;
void reset()
{
    for(int i=0; i<10010; i++)
    {
        vis[i] = 0;
        dis[i] = inf;
    }
}
int main()
{
    int n, e;
    while(cin >> n >> e){
    reset();
    for(int i=0; i<10010; i++)
    {
        G[i].clear();
     }
    for(int i=0; i<e; i++)
    {
        int u,v,cst;
        cin >> u >> v >> cst;
            G[u].push_back(make_pair(v,cst));
            G[v].push_back(make_pair(u,cst));
    }
    int source;
    source = 0;
    pii sr = make_pair(0,source);
    dis[source] = 0;
    pq.push(sr);
    while(!pq.empty())
    {
        pii u = pq.top();
        vis[u.second] = 1;
        pq.pop();
        for(int i=0; i<G[u.second].size(); i++)
        {
            pii v = G[u.second][i];
            if(!vis[v.first])
            {
                if(dis[v.first]>(dis[u.second]+v.second))
                {
                    dis[v.first] = dis[u.second]+v.second;
                    pii vv = make_pair(-dis[v.first], v.first);
                    pq.push(vv);
                }
            }
        }
    }

    int dis1[10010], dis2[10010];
    for(int i=0; i<n; i++)
    {
        dis1[i] = dis[i];
    }
    reset();

    source = n-1;
    sr = make_pair(0,source);
    dis[source] = 0;
    pq.push(sr);
    while(!pq.empty())
    {
        pii u = pq.top();
        vis[u.second] = 1;
        pq.pop();
        for(int i=0; i<G[u.second].size(); i++)
        {
            pii v = G[u.second][i];
            if(!vis[v.first])
            {
                if(dis[v.first]>(dis[u.second]+v.second))
                {
                    dis[v.first] = dis[u.second]+v.second;
                    pii vv = make_pair(-dis[v.first], v.first);
                    pq.push(vv);
                }
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        dis2[i] = dis[i];
    }
//    for(int i=0; i<n; i++)
//    {
//        printf("dis1[%d] = %d\n",i,dis1[i]);
//    }
//    printf("\n");
//    for(int i=0; i<n; i++)
//    {
//        printf("dis2[%d] = %d\n",i,dis2[i]);
//    }
    int res  = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<G[i].size(); j++)
        {
//            cout << dis1[i] << " " <<  dis2[G[i][j].first] << " "  << G[i][j].second << endl;
            if( (dis1[i] + dis2[G[i][j].first] + G[i][j].second) == dis1[n-1])
            {
                res += G[i][j].second;
            }
        }
 }
    cout << res*2 << endl;
    }
}
