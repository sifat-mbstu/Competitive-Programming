#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

int sz;
int dp[50][3];

int fun(int pos, int prev)
{
    if(pos==sz) {
        return 1;
    }
    
    int &ret = dp[pos][prev];
    if(ret!=-1)
        return ret;
    
    ret = 0;
    ret += fun(pos+1,0);
    
    if (prev!=1) {
        ret += fun(pos+1,1);
    }
    
    return ret;
    
}
int idx;

void path(int pos, int prev, int suru)
{
    if(pos==sz) return;
    int ret1=0,ret2=0;
    ret1 = fun(pos+1,0);
    
    if( prev!=1) {
        ret2 = fun(pos+1,1);
    }
    if(ret1>=idx) {
        if(suru)printf("0");
        path(pos+1,0,suru);
    }
    else {
        printf("1");
        idx -= ret1;
        path(pos+1,1,suru|1);
    }
}

int main()
{
    memset(dp,-1,sizeof(dp));
    sz = 43;
    fun(0,0);
    int tc,idd=0;
    scanf("%d",&tc);
    while(tc--)
    {
        int d;
        scanf("%d",&d);
        idx=d+1;
        printf("Case %d: ",++idd);
        path(0,0,0);
        printf("\n");
    }
}
