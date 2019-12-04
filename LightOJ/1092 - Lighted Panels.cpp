#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX/3
#define mx (1<<8)+5
int arr[210];
int dp[9][mx][mx];
int r,c,ret;
int fun(int pos, int cur, int pre)
{
    if(pos == r)
    {
        if(pre == ((1<<c)-1))return 0;
        return inf;
    }
    if(dp[pos][cur][pre]!=inf) return dp[pos][cur][pre];
    for(int i=0; i< (1<<c); i++)
    {
        int cnt = 0;
        int aa = pre;
        int bb = cur;
        int cc = arr[pos+1];
        for(int j=0; j<c; j++)
        {
            if(i & (1<<j))
            {
                cnt++;
                aa = aa ^ (1<<j);
                bb = bb ^ (1<<j);
                cc = cc ^ (1<<j);
                if(j-1>=0) aa = aa ^ (1<<j-1);
                if(j-1>=0) bb = bb ^ (1<<j-1);
                if(j-1>=0) cc = cc ^ (1<<j-1);
                if(j+1<c)  aa = aa ^ (1<<j+1);
                if(j+1<c)  bb = bb ^ (1<<j+1);
                if(j+1<c)  cc = cc ^ (1<<j+1);
            }
        }


        if(pos == 0 || aa == ((1<<c)-1))
        {
            dp[pos][cur][pre] = ret = min(dp[pos][cur][pre], cnt+fun(pos+1,cc,bb));
        }
    }
    return ret;
}
int main()
{
    int TC,idx = 0;
    scanf("%d",&TC);
    while(TC--){
    cin >> r >> c;
    for(int i=0; i<=r; i++)
    {
        for(int j=0; j<=(1<<c); j++)
        {
            for(int k=0; k<=(1<<c); k++)
            {
                dp[i][j][k] = inf;
            }
        }
    }
    ret = inf;
    char str[100];
    for(int i=0; i<r; i++)
    {
        scanf("%s",str);
        int val = 0;
        int k = 0;
        for(int j=c-1; j>=0; j--)
        {
            if(str[j]=='*')
            {
               // cout << "Hey\n" << endl;
                val = val | (1<<k);
            }
            k++;
        }
        arr[i] = val;
    }
    int ans = fun(0,arr[0],0);
    if(ans!=inf)printf("Case %d: %d\n",++idx,ans);
    else printf("Case %d: impossible\n",++idx);
    }
}
