///Accepted
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define mx 150
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
string s[150];
map<string,int> Map;
vi G[mx];
int disc[mx];
int low[mx], AP[mx],vis[mx],parent[mx];
int tim;
void ini()
{
    int i;
    for(i =0; i<mx; i++)
    {
        AP[i]=false;   //Initializing AP and vis array as false
        parent[i]=-1;         // Initializing parent of each vertex to -1
        G[i].clear();       // clearing the adjacency list.
        low[i]=0;
    }
    Map.clear();
    tim=0;
}

void dfs(int u)
{
    vis[u]=true;
    int i;

    low[u] = disc[u] = ++tim;

    int child=0;
    for(i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(vis[v]==false)
        {
            child++;
            parent[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if( (parent[u]!=-1) and ( low[v]>=disc[u] ) )
            {
                AP[u]=true;
            }
            if( (parent[u]==-1) and (child>1))
            {
                AP[u]=true;
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
//    FO;
    int n;
    int u, v;
    string s1, s2;
    int ind = 0;
    while(scanf("%d",&n)==1)
    {
    if(!n) break;
        if(ind>0) printf("\n");

    ini();
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n; i++)
    {
        cin >>s[i];
//        cout << s[i] << endl;
        Map[s[i]] = i;
    }
    int e;
    scanf("%d",&e);
    for(int i=0; i<e; i++)
    {
        cin >> s1 >> s2;
        u = Map[s1];
        v = Map[s2];
//        printf("u = %d - v = %d\n",u,v);
//        getchar();
        G[u].pb(v);
        G[v].pb(u);
    }
    for(int i=0; i<n; i++){
        if(!vis[i]){
                dfs(i);
        }
    }
//    cout << "\n\n--->POINTS\n";
    vector <string> ans;
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(AP[i]) {ans.pb(s[i]);cnt++;}
    }
    sort(ans.begin(),ans.end());
//    cout <<"points number = " << cnt << endl;

    printf("City map #%d: %d camera(s) found\n",++ind, cnt);
    for(int i=0; i<cnt; i++)
    {
        cout << ans[i] << endl;
    }
    }
}
