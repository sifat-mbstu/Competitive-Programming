#include<bits/stdc++.h>

using namespace std;

#define SIZE 10010

unsigned long long  status[SIZE];

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
    unsigned long long int n,i,num;
    sieve();
    scanf("%llu",&n);
    while(n--)
    {
        scanf("%llu",&num);
        for(i=num/2+1; ; i++)
        {
            if(status[i]==0)
            {
                printf("%llu\n",i);
                break;
            }
        }
    }
    return 0;
}
