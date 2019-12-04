#include<bits/stdc++.h>
using namespace  std;
vector<int> vec;
vector<int> G[105];
#define pii pair<int,int>
pii dp[105];
pii fun(int val)
{
    if(G[val].size()==0)
    {
        dp[val].first = 0;
        dp[val].second = val;
        return dp[val];
    }
    if(dp[val].first!=-1)
    {
        return dp[val];
    }
    pii ret;
    ret.first = 0;
    ret.second = 105;
    for(int i=0; i<G[val].size(); i++)
    {
        int cur = G[val][i];
        pii path = fun(cur);
        path.first++;
        if(path.first>=ret.first)
        {
            if(path.first == ret.first)
            {
                ret.second = min(ret.second,path.second);
            }
            else
            {
                ret.second = path.second;
            }
            ret.first = path.first;
        }
    }
    return dp[val] = ret;
}
int main()
{
    int n, start,ind=0;
    while(cin >> n){
    if(!n)break;
    cin >> start;
    for(int i=0; i<105; i++)
    {
        dp[i].first  = -1;
    }
    for(int i=0;; i++)
    {
        int u,v;
        cin >> u >> v;
        if(!u && !v) break;
        G[u].push_back(v);
    }
    pii res = fun(start) ;
    printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++ind,start,res.first,res.second);

    for(int i=0; i<101; i++)
        {
            G[i].clear();
        }
//    cout << res.first << " " << res.second << endl;
}
}
