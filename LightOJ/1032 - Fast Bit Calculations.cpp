#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define pb push_back
int arr[34],sz;
ll to[33], dp[33][2][2][31];
string s;
ll fun(int pos, int choto, int pre, int cnt)
{
    if(pos==sz)
    {
        return cnt;
    }
    ll &ret = dp[pos][choto][pre][cnt];
    if(ret !=-1)return ret;
    int lo = 0;
    int hi = 1;
    if(choto==0)
    {
        hi = s[pos]-'0';
    }
    ret = 0;
    for(int i=lo; i<=hi; i++)
    {
        ret += fun(pos+1, choto|(i<hi), i, cnt+(pre==1 && i==1));
    }
    return ret;
}
 
int main()
{
    to[0]=1;
    for(int i=1; i<=32; i++)
    {
        to[i] = to[i-1] * 2LL;
    }
    int tc,idx=0;
    scanf("%d",&tc);
    while(tc--)
    {
        ll N;
        scanf("%lld",&N);
        memset(dp,-1,sizeof(dp));
        bool flag = 0;
        s="";
        for(int i=31; i>=0; i--)
        {
            if(to[i]<=N)
            {
                N -= to[i];
                flag = 1;
                s += '1';
            }
            else if(flag)
            {
                s += '0';
            }
        }
        sz = s.size();
        ll res = fun(0,0,0,0);
        printf("Case %d: %lld\n",++idx,res);
    }
}