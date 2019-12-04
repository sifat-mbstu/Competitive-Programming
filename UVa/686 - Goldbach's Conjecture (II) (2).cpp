#include<bits/stdc++.h>
using namespace std;
# define MAX 10000000
unsigned long long int ara[MAX];
void sieve()
{
    unsigned long long i,sq,j;
    for(i = 0; i < MAX ; i++){ara[i]=0;}
    for(i = 4; i < MAX; i+=2){ara[i]=1;}
    sq = sqrt(MAX);
    for(i=3;i<=sq;i+=2)
        if(ara[i]==0)
    {
        for(j=i*2;j<=MAX;j+=i)
        {
            ara[j] = 1;
        }
    }
    ara[1] = 1;
}
int main()
{
    unsigned long long counts,num,j;
    sieve();
    while(scanf("%llu",&num)==1 && num!=0)
    {
    counts = 0;
    for(j=2;j<=num/2;j++)
    {
        if(ara[j]==0){if(ara[num-j]==0){counts++;}}
    }
    printf("%llu\n",counts);
    }
}
