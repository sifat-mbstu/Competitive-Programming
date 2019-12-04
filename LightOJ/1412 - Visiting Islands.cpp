///AC
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define mx 1000010
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)

vector<int>G[mx];
int vis[mx];
int Max=0,nd,siz;

struct str
{
    int dia,sz;
    str(int _dia, int _sz)
    {
        dia = _dia;
        sz = _sz;
    }
    bool operator < (const str& p)const
    {
        return dia>p.dia;
    }
};

struct st
{
    int num;
    int val;
    int res;
};

bool cmp1(st lh, st rh)
{
    return lh.num < rh.num;
}
bool cmp2(st lh, st rh)
{
    return lh.val < rh.val;
}
vector<str>trees;
st quer[mx];
void dfs_fnd(int src, int par, int dep)
{
    if(Max<dep)
    {
        Max = dep;
        nd = src;
    }
    siz++;
    for(int i=0; i<G[src].size(); i++)
    {
        int v = G[src][i];
        if(v!=par)
            dfs_fnd(v,src,dep+1);
    }
}
void dfs(int src, int par, int dep)
{
    vis[src] = 1;
    if(Max<dep)
    {
        Max = dep;
    }
    for(int i=0; i<G[src].size(); i++)
    {
        int v = G[src][i];
        if(v!=par)
            dfs(v,src,dep+1);
    }
}
pii fnd_dia_sz(int u)
{
    Max = 0;
    siz = 0;
    dfs_fnd(u,-1,1);
    Max = 0;
    dfs(nd,-1,1);
    return pii(Max,siz);
}
int main()
{
    int TC, cas = 0;
    scanf("%d",&TC);
    while(TC--)
    {
        int n,m;
        memset(vis,0,sizeof(vis));
        scanf("%d %d",&n, &m);
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d %d",&u, &v);
            G[u].pb(v);
            G[v].pb(u);
        }
        trees.clear();
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                pii ans = fnd_dia_sz(i);
                trees.push_back(str(ans.first,ans.second));
            }
        }
        sort(trees.begin(),trees.end());

        int q;
        scanf("%d",&q);
        for(int i=0; i<q; i++)
        {
            int v;
            scanf("%d",&quer[i].val);
            quer[i].num = i;
            quer[i].res = -1;
        }
        sort(quer,quer+q, &cmp2);
        int idx = 0;
        for(int i=0; i<trees.size(); i++)
        {
            int cdia = trees[i].dia;
            int csz = trees[i].sz;
//            cout << cdia << endl;
            if(idx < q && csz >= quer[idx].val)
            {
                while(idx < q && csz >= quer[idx].val)
                {
                    if(cdia>=quer[idx].val)
                        quer[idx].res = quer[idx].val;
                    else
                    {
                        int res = quer[idx].val - cdia;
                        quer[idx].res = cdia + 2*res;
                    }
                    idx++;
                }
            }
        }
        printf("Case %d:\n",++cas);
        sort(quer,quer+q, &cmp1);
        for(int i=0; i<q; i++)
        {
            if(quer[i].res==-1)
                printf("impossible\n");
            else
                printf("%d\n",quer[i].res-1);
        }
        for(int i=0; i<=n; i++)
            G[i].clear();
    }
}
