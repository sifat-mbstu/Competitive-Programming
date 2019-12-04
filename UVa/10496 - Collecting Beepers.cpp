#include<bits/stdc++.h>
using namespace std;
pair<int, int> Pair[20];
int cost[20][20],n;
int DP[21][1<<11];
int seton(int mask, int pos)
{
    return mask|(1<<pos);
}
int check(int mask, int pos)
{
    return mask&(1<<pos);
}
int fun(int pos,int mask)
{
    if(DP[pos][mask]!=-1) return DP[pos][mask];
    if(mask == (1<<(n+1))-1) return DP[pos][mask]=cost[pos][0];
    int ret = 1 << 28;
    for(int i=1; i<=n; i++)
    {
        if(check(mask,i)==0)
        {
            ret = min(ret, cost[pos][i] + fun(i, seton(mask,i)) );
        }
    }
    return DP[pos][mask]=ret;
}

int main()
{
    int TC;
    cin >> TC;
    while(TC--)
    {
        int r,c,x,y;
        scanf("%d %d",&r,&c);
        scanf("%d %d",&x,&y);
        int num_of_beeper;
        scanf("%d",&n);
        Pair[0].first = x, Pair[0].second = y;
        for(int i=1; i<=n; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            Pair[i].first = u;
            Pair[i].second = v;
        }
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                cost[i][j] = abs(Pair[i].first-Pair[j].first) + abs(Pair[i].second-Pair[j].second);
            }
        }
        memset(DP,-1,sizeof(DP));
        cout <<"The shortest path has length " << fun(0,1) << endl;
    }
}
