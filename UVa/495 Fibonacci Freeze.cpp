#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[100];
ll fib (ll n)
{
    if(n<0){return 0;}
    if(n<=1){return n;}
    if(dp[n]!=-1) { return dp[n]; }
    else
    {
            dp[n] = fib(n-1) + fib (n-2);
            return dp[n];
    }
}
int main()
{
    ll n,i;
    memset(dp, -1 , sizeof(dp));
    while(scanf("%lld",&n)==1)
    {
        i = fib(n);
        printf("The Fibonacci number for %lld is %lld\n",n,i);
    }
}
