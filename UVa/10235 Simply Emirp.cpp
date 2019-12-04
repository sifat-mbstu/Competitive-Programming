///Be aware of Palindrome :D

#include<bits/stdc++.h>
using namespace std;
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)

#define maxi 1000010
#define ll long long
ll ara[maxi];
vector <ll> prime;
void sieve()
{
    ll i,j;
    ara[1] = 1;
    ll sq = 1010;
    prime.push_back(2);
    for(i = 4; i <= maxi; i += 2){ara[i]  = 1;}
    for(i = 3; i < sq; i+=2)
    {
        if(ara[i] == 0){
        prime.push_back(i);
        for(j = i * i; j < maxi; j += (i*2))
        {
            ara[j] = 1;
        }
        }
    }
    for(i = sq; i < 3300; i++)
    {
        if(ara[i] == 0) prime.push_back(i);
    }
}
ll Reverse(ll N)
{
    ll sum = 0;
    while(N != 0)
    {
        sum = sum *10 + N % 10;
        N = N / 10;
    }
    return sum;
}
int main()
{
    //FI;FO;
    sieve();
    bool prime, emirp;
    ll N, rev;
    while(cin >> N){
    prime = emirp = 0 ;

    if(ara[N] == 0){prime = 1;
    rev = Reverse(N);
    if(ara[rev] == 0 && rev!= N){emirp = 1;}
    }
    if(emirp) {printf("%lld is emirp.\n",N);}
    else if(prime) {printf("%lld is prime.\n",N);}
    else {printf("%lld is not prime.\n",N);}
}
}
