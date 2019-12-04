///Accepted (0.22 Second)
/*
    In this Code We need find out how many primes in between a and b
    where 1 <= a,b < 2^31
    and abs(a-b) <= 100000
    Time Limit: 2 Seconds
*/
#include<bits/stdc++.h>
using namespace std;
#define Mx 400345
#define ll long long int
ll N = Mx, status[Mx];
ll prime[Mx];
bool is_prime[1000006];
ll k = 0;
void sieve()
{
    ll i, j, sqrtN;
    for( i = 4; i <= N >> 1; i++ ) status[i] = 0;
    sqrtN = (long long int)( sqrt((double)N) );
    prime[0] = 2;
    k=1;
    for( i = 3; i <= N; i += 2 )
    {
        if(status[i] == 0)
        {
            prime[k++] = i;
            for(j = i * i; j <= N; j += i + i)
            {
                status[j] = 1;
            }
        }
    }
}
int main()
{
    sieve();
    ll TC;
    ll ind=0;
    cin >> TC;
    while(TC--)
    {
        ll a, b;
        ll j=0;
        memset(is_prime, 0, sizeof(is_prime));
        cin >> a >> b;
        if(b<a) swap(a,b);
        j = b-a+1;
        ll sq = (long long int)( sqrt((double)(b)) );
        for(ll i=0; i<=sq && i<k; i++)
        {
            ll beg = (a/prime[i]) * prime[i];
            while(beg < a )
            {
                beg += prime[i];
            }
            if(beg == prime[i])
            {
                beg+=prime[i];
            }
            for(ll x = beg; x<=b; x+=prime[i])
            {
                is_prime[x-a] = 1;
            }
        }
        ll cnt = 0;
        for(ll i=a; i<=b; i++)
        {
            if(is_prime[i-a] == 0)
            {
                cnt++;
            }
        }
        if(a==1) cnt--;
        printf("Case %lld: %lld\n",++ind, cnt);
    }
}
