#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s;
ll mod = 1e9+7;
ll dp[1010][1025][2][2];
int k,sz, arr[2010];

ll fun(int pos, int mask, int suru, int choto) {

    if(pos==sz)
    {
        int cnt = arr[mask]+1;
        if(cnt==k && suru)
            return 1;
        return 0;
    }

    ll &ret = dp[pos][mask][suru][choto];
    
    if(ret != -1)
        return ret;
    int lo = 0, hi = 1;
    
    if(choto==0) {
        hi = s[pos]-'0';
    }
    
    ret = 0;
    for(int i=lo; i<=hi; i++) {
        ret += fun(pos+1,mask+i,suru|i>0, choto|(i<hi));
        ret %= mod;
    }
    return ret;
    
}

int main()
{
    arr[1] = 0;
    for(int i=2; i<=1000; i++)
    {
        int n = __builtin_popcount(i);
        arr[i] = arr[n]+1;
    }
    
    memset(dp,-1,sizeof(dp));
    cin >> s;
    scanf("%d",&k);
    sz = s.size();
    ll res;
    if(k==0)
        res = 1;
    else
    {
        res = fun(0,0,0,0);
        if(k==1)
            res--;
    }
    
    printf("%lld\n",res);
    
}
