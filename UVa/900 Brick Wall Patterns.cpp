#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[100];
ll fib(ll N)
{
    if(N<0){return 0;}
    if(N<4){return N;}
    if(dp[N]!=-1){return dp[N];}
    else {dp[N] = fib(N-1) + fib(N-2);
        return dp[N];}
}
int main()
{
    ll i,N;
    while(scanf("%lld",&N)==1){
            if(N==0){break;}
    for(i=0;i<90;i++)
    {
        dp[i] = -1;
    }
    ll res = fib(N);
    cout << res <<endl;
}
}
