#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N  100000010
#define sq 10000
vector <long> primes;
long long ara[N];
void sieve()
{
    ll i,j;
    primes.push_back(2);
    for(i=4;i < N; i += 2){ara[i] = 1;}
    ara[0] = 1;
    for(i=3;i<sq;i+=2)
    {
        if(ara[i]==0)
        {
            primes.push_back(i);
            for(j=i*i;j<=N; j += (2*i))
            {
                ara[j] = 1;
            }
        }
    }
    for(i=sq+1; i<N; i+=2)
    {
        if(ara[i]==0)
            primes.push_back(i);
    }
}
int main()
{
    ll  i,p,st,TC, n;
    sieve();
    cin >> n;
    for(i = 0; i < n;i++)
    {
        if(primes[i] >= n){ st = i; break;}
    }
    ll dif,n1,n2;
    ll Min = pow(2,32) + 1;
    n1 = -1;
    n2 = -1;
    for(i = st; i >= 0; i--)
    {
        p = n - primes[i];
        //cout << primes[i] << endl;
        if(ara[p] == 0)
        {
            dif = fabs(primes[i] - p);
            if(Min >= dif)
            {
                n1 = p;
                n2 = primes[i];
            }
        }
    }
    cout << n1 << " " << n2 << endl;
}

