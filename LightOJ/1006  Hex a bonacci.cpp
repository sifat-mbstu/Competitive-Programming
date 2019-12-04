#include<bits/stdc++.h>
using namespace std;
#define ll  unsigned long long
ll a, b, c, d, e, f;
int DP[10010];
ll fn( ll n )
{
    if( n == 0 ) return a%10000007;
    else if( n == 1 ) return b %10000007;
    else if( n == 2 ) return c%10000007;
    else if( n == 3 ) return d%10000007;
    else if( n == 4 ) return e%10000007;
    else if( n == 5 ) return f%10000007;
 
    if(DP[n]!=-1)
    {
        DP[n] = DP[n] % 10000007;
        return DP[n];
    }
    else
    {
        DP[n]=0;
        DP[n] += (fn(n-1) %10000007);
        DP[n] += (fn(n-2) %10000007);
        DP[n] += (fn(n-3) %10000007);
        DP[n] += (fn(n-4) %10000007);
        DP[n] += (fn(n-5) %10000007);
        DP[n] += (fn(n-6) %10000007) ;
        return DP[n];
    }
}
int main()
{
    ll n, caseno = 0, cases;
    scanf("%llu", &cases);
    while( cases-- )
    {
        memset(DP, -1, sizeof(DP));
        scanf("%llu %llu %llu %llu %llu %llu %llu", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %llu: %llu\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
 