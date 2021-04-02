#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MEM(a,val) memset(a,val,sizeof(a))

ll dp[12][3][3][3], n,n1;
ll dp_way[12][3][3];
string s,s1;

ll way(ll pos, ll boro, ll choto)
{
    if(pos==n) {return 1;}
    ll &ret = dp_way[pos][boro][choto];
    if(ret!=-1) return ret;
    ll lo=0,hi=9;
    if(boro==0) lo = s1[pos]-'0';
    if(choto==0) hi = s[pos]-'0';
    ret= 0;
    for(ll i=lo; i<=hi; i++)
    {
        ret += way(pos+1, boro|(i>lo),choto | (i<hi) );
    }
    return ret;
}

ll fun(ll pos,ll boro, ll choto, ll suru)
{
    if(pos==n) return 0;
    ll &ret = dp[pos][boro][choto][suru];
    if(ret!=-1) return ret;
    ll lo=0,hi=9;
    if(boro==0) lo = s1[pos]-'0';
    if(choto==0) hi = s[pos]-'0';
    ret= 0;
    for(ll i=lo; i<=hi; i++)
    {
        ll cntway=0;
        if(i==0&&suru) cntway = way(pos+1, boro|(i>lo),choto | (i<hi));
        ret += cntway + fun(pos+1, boro|(i>lo),choto | (i<hi), suru|(i>0));
    }
    return ret;
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
        MEM(dp_way,-1);
        char strs[12];
        sprintf(strs,"%lld",a1);
        s1 = strs;
        sprintf(strs,"%lld",a2);
        s = strs;
        while(s1.size()!=s.size())
            s1.insert(s1.begin(),'0');
        n = s.size();
        ans = fun(0,0,0,0)+(a1==0);
        printf("Case %lld: %lld\n",++idx,ans);
    }
}
