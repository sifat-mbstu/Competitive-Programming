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
    for(i=0;i<N;i++)
    {
        ara[i] = 0;
    }
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
/*
void ano()
{
    ll i,j;
    for(i=N+1; i < 1000000000; i+=2)
    {
        for(j=0;j < 57614; j++){
        if(i%primes[j] == 0){break;}
        }
        if(j==57614){primes.push_back(i);}
    }
}
*/
int main()
{
    ll  i,digit,power,res,TC, num;
    sieve();
   // ano();

}
