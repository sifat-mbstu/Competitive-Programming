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


#define all(a) a.begin(),a.end()
#define _max(a,b,c) Max(a,Max(b,c))
#define _min(a,b,c) Min(a,Min(b,c))

#define FOR(i,a,b) for(int i=a;i<b; i++)

#define MEM(a,val) memset(a,val,sizeof(a))

#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d%d",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

#define sfl(a) scanf("%lld",&a)
#define sfl2(a,b) scanf("%lld%lld",&a,&b)
#define sfl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define sfl4(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)

#define tover(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define nover(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW

#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
#define MOD 1000000007
#define inf INT_MAX/3
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
#define pii pair<int,int>
#define mx 10010
struct st
{
    int v,w,ty;
    st(int _v, int _w, int _ty)
    {
        v = _v; w = _w; ty = _ty;
    }
};
int n,d;
vector<st>G[mx];
struct node
{
    int v,cst,cnt;
    node(int _v, int _cst, int _cnt)
    {
        v = _v; cst = _cst; cnt = _cnt;
    }
    bool operator < (node p)const
    {
        return cst>p.cst;
    }
};
int dijkstra()
{
    int dis[d+1][n+1];
    memset(dis,1,sizeof(dis));
//    cout << dis[0][0] << endl;
    priority_queue<node>pq;
    pq.push(node(0,0,0));
    dis[0][0] = 0;
    while(!pq.empty())
    {
        node top = pq.top();
        pq.pop();
        int u = top.v;
        int cst = top.cst;
        int cnt = top.cnt;
        if(u==n-1)return cst;

        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i].v;
            int nxtcst = cst + G[u][i].w;
            int nxtcnt = cnt + G[u][i].ty;
//            cout << dis[nxtcnt][v] << endl;
            if(nxtcnt<=d && nxtcst <dis[nxtcnt][v])
            {
                dis[nxtcnt][v] = nxtcst;
                pq.push(node(v,nxtcst,nxtcnt));
            }
        }
    }
    return -1;
}
int main()
{
    int TC,idx=0;
    sf(TC);
    while(TC--)
    {
        int m,k;
        sf4(n,m,k,d);
        int u,v,w;
        while(m--)
        {
            sf3(u,v,w);
            G[u].pb(st(v,w,0));
        }
        while(k--)
        {
            sf3(u,v,w);
            G[u].pb(st(v,w,1));
        }
        int res = dijkstra();
        if(res==-1) printf("Case %d: Impossible\n",++idx);
        else printf("Case %d: %d\n",++idx,res);
        for(int i=0; i<=n; i++)G[i].clear();
    }

}
