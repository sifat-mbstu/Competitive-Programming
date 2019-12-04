/// Idea Mahbubul Hasan Book :)
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n;
int pre[20010], post[20010];
int mpre[20010], mpost[20010];
int vis[20010];
vector<int>tree[200010];
int Min = INT_MAX;
int res;
void reset()
{
    Min = INT_MAX;
    for(int i=0; i<200001; i++)
        tree[i].clear();
    memset(vis,0,sizeof(vis));
}
void dfs(int u, int sum)
{
    bool flag = 0;
    vis[u] = 1;
    for(int i=0; i<tree[u].size(); i++)
    {
        int v = tree[u][i];
        if(!vis[v])
        {
            flag = 1;
            dfs(v,sum+u);
        }
    }
    if(!flag)
    {
        if(Min> sum+u)
        {
            res = u;
            Min = sum+u;
        }
    }
}

void fun(int pb, int pe, int qb, int qe)
{
    if(pb>pe || qb > qe) return;
    int root = post[qe];
    int pos = mpre[root];
    int left = pos-pb;
    int r8 = pe-pos;
/// left
    if(left>0)
    {
        int lpb, lpe, lqb, lqe;
        lpb = pb;
        lpe = pos-1;
        lqb = qb;
        lqe = qb+(pos-pb)-1;
        tree[root].pb(post[lqe]);
        tree[post[lqe]].pb(root);
        fun(lpb,lpe,lqb,lqe);
    }
/// Right
    if(r8 > 0)
    {
        int rpb, rpe, rqb, rqe;
        rpb = pos+1;
        rpe = pe;
        rqb = qe-r8;
        rqe = qe-1;

        tree[root].push_back(post[rqe]);
        tree[post[rqe]].push_back(root);

        fun(rpb, rpe, rqb, rqe);
    }
}
int main()
{
    string s1,s2;
    while(getline(cin,s1))
    {
        reset();
        getline(cin,s2);
        stringstream ss;
        ss << s1;
        int v;
        int id1 = 0, id2 = 0;
        while(ss >> v)
        {
            pre[id1++] = v;
        }
        stringstream sst;
        sst << s2;
        while(sst >> v)
        {
            post[id2++] = v;
        }
        n=id1;
        for(int i=0; i<n; i++)
        {
            mpost[post[i]] = i;
            mpre[pre[i]] = i;
        }
        fun(0,n-1,0,n-1);
        dfs(post[n-1],0);
        cout << res << endl;
    }
}
