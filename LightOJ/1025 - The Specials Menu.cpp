///AC
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[65][65];
string s;
ll fun(int pos, int bckpos)
{
    if(pos>=bckpos)
    {
        if(pos>bckpos)
            return 0;
        return 1;
    }
    ll &ret = dp[pos][bckpos];
    if(ret!=-1) return ret;

    ret=0;
    if(s[pos]==s[bckpos]) ret += 1 + fun(pos+1,bckpos) + fun(pos,bckpos-1);
    else ret += fun(pos+1,bckpos) + fun(pos,bckpos-1)-fun(pos+1,bckpos-1);
    return ret;
}
int main()
{
    int tc,idx=0;
    scanf("%d",&tc);
    while(tc--)
    {
        memset(dp,-1,sizeof(dp));
        cin >> s;
        ll sum = fun(0,s.size()-1);
        printf("Case %d: %lld\n",++idx,sum);
    }
}
