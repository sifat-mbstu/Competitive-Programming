#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define ll long long

ll dp[12][3][3][12], n;
char s[12];

ll fun(ll pos, ll choto, ll suru, ll cnt)
{
    if(pos==n)
        return cnt;
    ll &ret = dp[pos][choto][suru][cnt];
    if(ret!=-1)
        return ret;
    ll lo=0,hi=9;
    if(choto==0)
        hi = s[pos]-'0';
    ret= 0;
    for(ll i=lo; i<=hi; i++)
    {
        ret += fun(pos+1, choto | (i<hi), suru|(i>0), (i==0 && suru)+cnt);
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
        scanf("%lld %lld",&a1,&a2);
        ll ans;
        if(a1==0 && a2==0)
        {
            ans = 1LL;
        }
        else
        {
            a1--;
            ll cnt1;
            if(a1<0)
            {
                cnt1=0;
            }
            else
            {
                memset(dp,-1,sizeof(dp));
                sprintf(s,"%lld",a1);
                n = strlen(s);
                cnt1 = fun(0,0,0,0)+1;
            }
            memset(dp,-1,sizeof(dp));
            sprintf(s,"%lld",a2);
            n = strlen(s);
            ll cnt2 = fun(0,0,0,0)+1;
            ans = cnt2-cnt1;
        }
        printf("Case %lld: %lld\n",++idx,ans);
    }
}
