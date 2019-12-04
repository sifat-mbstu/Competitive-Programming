#include<bits/stdc++.h>
using namespace std;
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)

#define maxi 1000010
#define ll long long
ll ara[maxi];
ll dis[maxi];
vector <ll> prime;
vector <ll> det[32010];
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
    for(i = sq; i < 33000; i++)
    {
        if(ara[i] == 0) prime.push_back(i);
    }
    ll len = prime.size();
    for(i = 0; i < len-1; i++)
    {
        dis[i] = prime[i+1] - prime[i];
    }


}
ll det_prime(ll a, ll b)
{
    ll i,z;
    ll len = prime.size(),start,fin;
    for(i = 0; i < len; i++)
    {
        if(prime[i] >= a)
        {
            start = i;
            break;
        }
    }
    for( ; i < len; i++)
    {
        if(prime[i] >= b)
        {
            fin = i;
            break;
        }
    }
    z = -1;
    for(i = start; i < fin; i++)
    {
        if(dis[i] == dis[i-1])
        {
            ++z;
            det[z].push_back(prime[i-1]);
            det[z].push_back(prime[i]);
            det[z].push_back(prime[i+1]);
            //printf("%lld %lld %lld", prime[i-1], prime[i], prime[i+1]);
            i++;
                while(dis[i] == dis[i-1])
                {
                    det[z].push_back(prime[i+1]);
                    i++;
                    if(i > fin){break;}
                }
        }
    }
    return z;
}
int main()
{
    //FI;FO;
    ll x,y,i;
    sieve();
    bool prime, emirp;
    ll N, rev,Size;
    while(cin >> x >> y){
    if(x > y){ swap(x,y);}
    Size = det_prime(x,y);
    for(i = 0; i < Size; i++)
        {

        }
}
}

