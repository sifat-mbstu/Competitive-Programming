#include<bits/stdc++.h>
using namespace std;
vector<int>G[1010];
int vis[1010];
int cnt1 = 0;
int cnt2 = 0;
bool flag = 1;
void dfs(int src, int cur)
{
    if(!flag) return;
    if(vis[src])
    {
        if(vis[src]!=cur) flag = 0;
        return;
    }
    vis[src] = cur;
    if(cur==1)cnt1++;
    else cnt2++;
    int nxt;
    if(cur==1) nxt =2;
    else nxt = 1;
    for(int i=0; i<G[src].size(); i++)
    {
        int v = G[src][i];
        dfs(v,nxt);
    }
}
int main()
{
    int n,m;
    int TC;
    cin >> TC;
    while(TC--)
    {
        scanf("%d",&n);
        scanf("%d",&m);
        memset(vis,0,sizeof(vis));
        flag = 1;
        for(int i=0; i<300; i++)
        {
            G[i].clear();
        }
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d %d",&u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int cnt = 0;
        for(int i=0; i<n; i++)
        {

            if(!vis[i]&&G[i].size())
            {
                cnt1 = 0;
                cnt2 = 0;
                dfs(i,1);
                cnt += min(cnt1,cnt2);
            }
            else if(G[i].size()==0)
            {
                cnt++;
            }
        }
        if(flag)
        {
            cout << cnt << endl;
        }
        else cout <<"-1" << endl;
    }
}
