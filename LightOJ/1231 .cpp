#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll use[105],k,n,co[105],dp[105][105];
ll coin(ll i,ll amount)
{
    if(i>=n)
    {
        if(amount==k)return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1)return dp[i][amount];
    ll cnt1=0;
    for(ll j=1;j<=use[i];j++)
    {
        if((co[i]*j)+amount<=k)
        {
            cnt1 += coin(i+1,amount+(co[i]*j))%100000007;
        }
        else break;
    }
    cnt1+=coin(i+1,amount)%100000007;
    dp[i][amount]=cnt1%100000007;
    return dp[i][amount];

}
int main()
{
    ll i,j,tc;
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld %lld",&n,&k);
        memset(dp,-1,sizeof(dp));
        memset(co,0,sizeof(co));
        memset(use,0,sizeof(use));
        //cout<<"---------1"<<endl;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&co[i]);
        }
        //cout<<"--------2"<<endl;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&use[i]);
        }
        ll res = coin(0,0);
        printf("%lld\n",res);
    }
    return 0;
}
