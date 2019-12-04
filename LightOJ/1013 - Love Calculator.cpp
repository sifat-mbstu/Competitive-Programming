///Accepted (0.008 Second)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll lenA,lenB;
ll DP[31][31],n;
ll dp[62][31][31];
string A,B;
ll LCS(ll i, ll j)
{
    if(i==lenA || j==lenB) {return DP[i][j] = 0;}
    if(DP[i][j]!=-1) return DP[i][j];
    ll ans = 0;
    if(A[i]==B[j])
    {
        ans = 1+LCS(i+1,j+1);
    }
    else
    {
        ll val1 = LCS(i+1,j);
        ll val2 = LCS(i,j+1);
        ans = max(val1, val2);
    }
    return DP[i][j] = ans;
}

ll fun(ll len, ll i, ll j)
{
    if(i==lenA && j==lenB)
    {
        if(len==n) return 1;
        return 0;
    }
    if(dp[len][i][j]!=-1) return dp[len][i][j];
    ll ans = 0;
    if(A[i]==B[j]) ans = fun(len+1, i+1, j+1);
    else
    {
        ll a = 0;
        ll b = 0;
        if(i<lenA)a = fun(len+1, i+1, j);
        if(j<lenB)b = fun(len+1, i, j+1);
        ans = a+b;
    }
    return dp[len][i][j] = ans;
}

int main()
{
    ll tc, ind = 0;
    cin >> tc;
    while(tc--){
    cin >> A >> B;
    memset(DP,-1,sizeof(DP));
    memset(dp,-1,sizeof(dp));
    lenA = A.size();
    lenB = B.size();

    n = lenA + lenB - LCS(0,0);

    printf("Case %lld: %lld %lld\n",++ind, n, fun(0, 0, 0));
    }
}

