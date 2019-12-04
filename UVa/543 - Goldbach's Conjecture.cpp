#include<bits/stdc++.h>
using namespace std;
#define SIZE 10000000

long long int status[SIZE];
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
}

int main()
{
    long long int n,i,t;
    sieve();
    //printf("Enter a number to check goldbach: ");
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
        {
            break;
        }
        t=1;
        for(i=0; i<n; i++)
        {
            if(status[i]==0 && status[n-i]==0)
            {
                printf("%lld = %lld + %lld\n",n,i,n-i);
                t=0;
                break;
            }
        }
        if(t)
        {
            printf("Goldbach's conjecture is wrong.\n");
        }
    }
    return 0;
}
