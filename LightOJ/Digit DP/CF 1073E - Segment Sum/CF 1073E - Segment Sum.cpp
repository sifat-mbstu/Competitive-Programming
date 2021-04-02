#include<bits/stdc++.h>
using namespace std;
#define ll long long

int k,sz;
string A,B;
ll mod = 998244353, dp[20][1024][2][2], dpway[20][1024][2][2], ten[22];

ll funway(int pos, int mask, int choto, int boro) {
    
    if(pos==sz)
    {
        if(__builtin_popcount(mask) <= k) return 1;
        return 0;
    }
    
    ll &ret = dpway[pos][mask][choto][boro];
    if(ret!=-1)return ret;
    int lo = 0, hi = 9;
    if(choto==0) hi = B[pos]-'0';
    if(boro==0) lo = A[pos] - '0';
    ret = 0;
    for(int i=lo; i<=hi; i++)
    {
        int nw_mask;
        if(i==0 && mask==0) nw_mask = mask;
        else nw_mask = mask | (1<<i);
        ret += funway(pos+1,nw_mask ,choto|(i<hi),boro|(i>lo));
        ret %= mod;
    }
    return ret;
    
}

ll fun(int pos, int mask, int choto, int boro)
{
    if(pos==sz) return 0;
    ll &ret = dp[pos][mask][choto][boro];
    if(ret != -1) return ret;
    int lo = 0, hi = 9;
    if(choto==0) hi = B[pos]-'0';
    if(boro==0) lo = A[pos] - '0';
    ret = 0;
    for(int i=lo; i<=hi; i++)
    {
        ll way = 0;
        int nw_mask = 0;
        if(i==0 && mask==0) nw_mask = 0;
        else
        {
            nw_mask = mask | (1<<i);
            way = funway(pos+1,nw_mask, choto|(i<hi),boro|(i>lo));
        }
        ret += ((ten[sz-pos-1]*i) %mod * way) %mod;
        ret += fun(pos+1,nw_mask ,choto|(i<hi),boro|(i>lo)) %mod;
        ret %= mod;
    }
    return ret;
    
}
int main()
{
    
    ten[0] = 1;
    for(int i=1; i<=18; i++)
    {
        ten[i] = ten[i-1]*10LL; ten[i] %= mod;
    }
    memset(dp,-1,sizeof(dp));
    memset(dpway,-1,sizeof(dpway));
    funway(0,0,0,0);
    cin >> A >> B >> k;
    while(B.size()>A.size()) A.insert(A.begin(),'0');
    sz = A.size();
    ll res = fun(0,0,0,0);
    printf("%lld\n",res);
    
}
