#include<bits/stdc++.h>
using namespace std;
#define ll long long
void prime_factoriazation(ll n)
{
    ll cnt, i;
    for(i=2; i<=sqrt(n); i++)
    {
        if(n%i == 0)
        {
            cnt = 0;
            while(n%i == 0)
            {
                n /= i;
                cnt++;
            }
            printf("(%lld^%lld) ", i, cnt);
        }
        if(n==1) cout << endl;
    }
    if(n!=1)printf("(%lld^%lld)\n", n, 1);
}
int main()
{
    ll n;
    while(scanf("%lld",&n) ==1)
    {
        prime_factoriazation(n);
    }
    return 0;
}
