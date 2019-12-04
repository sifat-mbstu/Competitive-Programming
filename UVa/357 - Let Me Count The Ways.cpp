#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n = 5;
ll DP[6][30010];
ll a[]={1,5,10,25,50};

ll f(ll pos, ll sum)
{
    if(DP[pos][sum]!=-1) return DP[pos][sum];
    if(sum<0) return 0;
    if(pos==n)
    {
        if(sum == 0) return 1;
        return 0;
    }
    ll a1 = f(pos, sum-a[pos]);
    ll a2 = f(pos+1, sum);
    return DP[pos][sum] = a1+a2;
}

int main()
{
    ll val;
    memset(DP,-1,sizeof(DP));
    while(scanf("%lld",&val)==1)
    {
        ll ans = f(0,val);
       if(ans==1) printf("There is only %lld way to produce %lld cents change.\n",ans,val);
       else
       {
           printf("There are %lld ways to produce %lld cents change.\n",ans,val);
       }

    }
}
