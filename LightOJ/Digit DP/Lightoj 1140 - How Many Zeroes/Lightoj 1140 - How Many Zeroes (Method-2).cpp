#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MEM(a,val) memset(a,val,sizeof(a))

ll dp[12][3][3][3][12], n,n1;
string s,s1;

ll fun(ll pos,ll boro, ll choto, ll suru, ll cnt)
{
    if(pos==n) return cnt;
    ll &ret = dp[pos][boro][choto][suru][cnt];
    if(ret !=-1) return ret;
    ll lo=0,hi=9;
    if(boro ==0) lo = s1[pos]-'0';
    if(choto==0) hi = s[pos]-'0';
    ret = 0;
    for(ll i=lo; i<=hi; i++)
    ret += fun(pos+1, boro|(i>lo),choto | (i<hi), suru|(i>0), (i==0 && suru)+cnt);
    return dp[pos][boro][choto][suru][cnt] = ret;
}

int main()
{
    ll tc,idx=0;
    scanf("%lld",&tc);
    while(tc--)
    {
        ll a1,a2;
        scanf("%lld %lld",&a1, &a2);
        ll ans;
        MEM(dp,-1);
        char strs[12];
        sprintf(strs,"%lld",a1);
        s1 = strs;
        sprintf(strs,"%lld",a2);
        s = strs;
        while(s1.size()!=s.size())
            s1.insert(s1.begin(),'0');
        n = s.size();
        ans = fun(0,0,0,0,0)+(a1==0);
        printf("Case %lld: %lld\n",++idx,ans);
    }
}
