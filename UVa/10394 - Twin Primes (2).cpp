#include<bits/stdc++.h>

using namespace std;

#define SIZE 20000000

unsigned long long  status[SIZE];
unsigned long long  prime[10000000];

void sieve()
{
    long long int i,j;
    for(i=0; i<SIZE; i++) status[i]= 0;
    long long int sq = sqrt(SIZE);
    for(i=4; i<=SIZE; i+=2) status[i] = 1;
    for(i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for(j=2*i; j<=SIZE; j+=i) status[j]=1;
        }
    }
    status[1] = 1;
    unsigned long long primes = 0;
   for(i=0;i<SIZE;i++)
   {
       if(status[i]==0 && status [i+2]==0)
       {
           prime[primes]=i;
           primes++;
       }
   }
}

int main()
{
    unsigned long long int n;
    sieve();
    while(scanf("%lld",&n)==1){
    printf("(%llu, %llu)\n",prime[n],prime[n]+2);
    }
    return 0;
}
