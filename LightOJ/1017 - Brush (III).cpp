/// IDEA: SHAKIL VAI (EASY)
/// AC
#include<bits/stdc++.h>
using namespace std;
int n,w,k,v;
int y[10010];
int dp[200][200];
int fun(int pos, int mov)
{
    if(pos>=n || mov >= k) return 0;
    if(dp[pos][mov]!=-1) return dp[pos][mov];
    int cnt = 0;
    int i;
    for(i=0; i+pos<n; i++)
    {
        if(y[pos]+w>=y[pos+i]){cnt++;}
        else break;
    }
    return dp[pos][mov] = max(cnt+fun(pos+i,mov+1), fun(pos+1,mov));
}
int main()
{
    int tc,idx=0;
    scanf("%d",&tc);
    while(tc--){
    scanf("%d %d %d",&n,&w,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&v,&y[i]);
    }
    sort(y,y+n);
    memset(dp,-1,sizeof(dp));
    printf("Case %d: %d\n",++idx,fun(0,0));
    }
}
