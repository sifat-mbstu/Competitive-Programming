#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[110][110], dp[110][110];
int main()
{
    ll TC, tc=0;
    scanf("%lld",&TC);
    while(TC--){
    memset(a, 0, sizeof(a));
    memset(dp, 0, sizeof(dp));
    ll N;
    scanf("%lld",&N);
    for(ll i=0; i<N; i++)
    {
        for(ll j=0; j<=i; j++)
        {
            scanf("%lld", &a[i][j]);
        }
    }
    for(ll i=N; i<2*N-1; i++)
    {
        for(ll j=0 ; j<=(2*N-2-i); j++)
        {
            scanf("%lld",&a[i][j]);
        }
    }
    dp[0][0] = a[0][0];
    for(ll i=0; i<N-1; i++)
    {
        for(ll j=0; j<=i; j++)
        {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + a[i+1][j+1]);
        }
    }
    for(ll i=N; i<(2*N-1); i++)
    {
            for(ll j=0; j<=(2*N-2-i); j++)
        {
           ll y = max(dp[i-1][j], dp[i-1][j+1]);
           dp[i][j] = a[i][j] + y;
        }
    }
    printf("Case %lld: %lld\n",++tc, dp[2*N-2][0]);
    }
}
