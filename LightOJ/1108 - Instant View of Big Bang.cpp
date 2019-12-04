///ACCEPTED :)

///   |----------------------------|
///   | BISMILLAHIR RAHMANIR RAHIM |
///   |----------------------------|

///       _______  __   ________   ___   .___________.
///      /       ||  | |   ____|  /   \  |           |
///     |   (----'|  | |  |__    /  ^  \ `---|  |----`
///      \   \    |  | |   __|  /  /_\  \    |  |
///  |----)   |   |  | |  |    /  _____  \   |  |
///  |_______/    |__| |__|   /__/     \__\  |__|
///


///**********************************************************//
#include<bits/stdc++.h>
using namespace std;

#define pb push_back

#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d%d",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

#define vi vector<int>
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
#define inf INT_MAX/3
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
#define pii pair<int,int>
#define mx 1010
struct st
{
    int u,v,w;
    st(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};

vector<st> node;
int vis[mx];
bool update = 0;
int res[mx], dis[mx];
vi R[mx];
void reset(int nn)
{
    node.clear();
    for(int i=0; i<nn; i++)
    {
        R[i].clear();
        res[i] = 0;
        dis[i] = inf;
        vis[i] = 0;
    }
}
void bellman(int src, int n, int e)
{
    for(int i=0; i<n; i++)
        dis[i] = inf;

    dis[src] = 0;
    for(int step = 0; step<n; step++)
    {
        update = 0;
        for(int i=0; i<node.size(); i++)
        {
            int u = node[i].u;
            int v = node[i].v;
            int w = node[i].w;
            if(dis[u]==inf) continue;
            if(dis[v]>dis[u]+w)
            {
                update = 1;
                dis[v] = dis[u]+w;
            }
        }
        if(update ==0) break;
    }
    if(!update)
        return;

    for(int step = 0; step<n; step++)
    {
        for(int i=0; i<node.size(); i++)
        {
            int u = node[i].u;
            int v = node[i].v;
            int w = node[i].w;
            if(dis[u]==inf)
                continue;
            if(dis[v]>dis[u]+w)
            {
//                printf("==>%d - %d\n",u,v);
                res[v] = 1;
                update = 1;
                dis[v] = dis[u]+w;
            }

        }
    }
}
void dfs(int src)
{
    if(vis[src]) return;
    vis[src] = 1;
    for(int i=0; i<R[src].size(); i++)
    {
        int v = R[src][i];
//        cout << "gotta = " << v << endl;
        if(!vis[v]) dfs(v);
    }
}
int main()
{
//    FO;
    int TC, idx = 0;
    sf(TC);
    while(TC--)
    {
        int n,m;
        sf2(n,m);
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            sf3(u,v,w);
            R[v].pb(u);
            node.pb(st(v,u,w));
        }
        for(int i=0; i<n; i++)
        {
            R[n].pb(i);
            node.pb(st(n,i,1));
        }
        bellman(n,n,m);
        printf("Case %d:",++idx);
        bool yes = 0;
            for(int i=0; i<n; i++)
            {
                if(res[i])
                {
                    dfs(i);
                }
            }
            for(int i=0; i<n; i++)
            {
                if(vis[i]) {printf(" %d",i); yes = 1;}
            }
            if(!yes)printf(" impossible");

            printf("\n");

        reset(n+1);
    }
}
