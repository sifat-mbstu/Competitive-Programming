#include<bits/stdc++.h>
using namespace std;
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
#define vi vector<int>
#define xx first
#define yy second
#define pb push_back
#define mx 10001
vi adj[mx];
int disc[mx];
int low[mx],vis[mx],parent[mx];
vector <pair <int,int> > AB;
int tim;
int cnt = 0;
void ini()
{
    int i;
    for(i =0; i<mx; i++)
    {
        vis[i]=false;
        parent[i]=-1;
        adj[i].clear();
        low[i]=0;
    }
    AB.clear();
    tim=0;
    cnt=0;
}
void dfs(int u)
{
    vis[u]=true;
    int i;
    low[u] = disc[u] = ++tim;
    int child=0;
    for(i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(vis[v]==false)
        {
            child++;
            parent[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if( low[v]>disc[u])
            {
                if(u<v) AB.pb(make_pair(u,v));
                else AB.pb(make_pair(v,u));
            }
        }
        else if(v!=parent[u])
        {
            low[u] = min(low[u],disc[v]);
        }
    }
}
int main()
{
    int TC,IND=0;
    scanf("%d",&TC);
    while(TC--)
    {
        ini();
        int node, edge;
        cin >> node;
        for(int i=0; i<node; i++)
        {
            int u, num;
            scanf("%d (%d)",&u,&num);
            while(num--){
            int v;
            scanf("%d",&v);
            adj[u].pb(v);
            adj[v].pb(u);
            }
        }
        for(int i=0; i<node; i++)
        {
            if(!vis[i])dfs(i);
        }
        printf("Case %d:\n",++IND);
        sort(AB.begin(),AB.end());
        cout << AB.size() << " critical links" << endl;
        for(int i=0; i<AB.size(); i++)
        {
            cout << AB[i].xx << " - " << AB[i].yy << endl;
        }
    }
}
