#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX/3
int n;
int cost[21][4];
int DP[21][4];
int fun(int pos, int prev)
{
    if(pos==n){return 0;}
    if(DP[pos][prev]!=-1) return DP[pos][prev];
    int Min = inf;
    for(int i=0; i<3; i++)
    {
        if(i!=prev)
        {
            Min = min(Min,cost[pos][i]+fun(pos+1, i));
        }
//        cout << Min << endl;
    }
    return DP[pos][prev] = Min;
}
int main()
{
    int TC,ind=0;
    cin >> TC;
    while(TC--){
    cin >> n;
    memset(DP,-1,sizeof(DP));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    printf("Case %d: %d\n",++ind,fun(0,10));
}
}
