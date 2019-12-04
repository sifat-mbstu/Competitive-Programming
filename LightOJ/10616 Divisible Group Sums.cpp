///Accepted : (0.010 Second)
#include<bits/stdc++.h>
using namespace std;
int n,m,d;
int arr[205];
int dp[201][201][21];
int fun(int pos, int taken, int sum)
{
    if(taken>m) return 0;
    if(pos==n)
    {
        if(taken == m)
        {
            if(sum%d==0) return 1;
        }
        return 0;
    }
    if(dp[pos][taken][sum]!=-1) return dp[pos][taken][sum];
    int a = 0, b = 0;
    int new_sum = (sum%d+arr[pos]%d)%d;
    if(new_sum<0) new_sum+=d;
    a = fun(pos+1, taken+1, new_sum);
    b = fun(pos+1, taken, sum);
    return dp[pos][taken][sum] = a+b;
}
int main()
{
    int q, ind =0;
    while(scanf("%d %d",&n, &q)==2)
    {
        if(!n && !q) break;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
        }
        printf("SET %d:\n",++ind);
        int query = 0;
        while(q--)
        {
            memset(dp,-1,sizeof(dp));
            scanf("%d %d",&d, &m);
            printf("QUERY %d: %d\n",++query, fun(0,0,0) );
        }
    }
}
