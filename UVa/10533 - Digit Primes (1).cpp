#include<bits/stdc++.h>
using namespace std;
#define Max 1000010
long long int ara[Max],prime[Max];
void sieve()
{
    long long int i,j;
    for(i=0; i<Max; i++) ara[i]= 0;
    for(i=4; i<Max; i+=2)
    {
        ara[i]=1;
    }
    long long int sq = sqrt(Max);
    for(i=3; i<sq; i+=2)
    {
        if(ara[i]==0)
        {
            for(j=2*i; j<Max; j+=i)
            {
                ara[j]=1;
            }
        }
    }
    ara[1]=1;
}
int main()
{
    long long int i,up,down,num,sum,counts=0,cases;
    sieve();
    for(i=2; i<=Max; i++)
    {
        if(ara[i]==0)
        {
            sum = 0;
            num=i;
            while(num!=0)
            {
                sum = sum+num%10;
                num/=10;
            }
            if(ara[sum] == 0)
            {
                //      printf("Prime == %lld\n",i);
                prime[i]=++counts;
                //printf("prime[i] == %lld ",counts);
            }
            else
            {
                prime[i] = counts;
            }
        }
        else
        {
            prime[i]=counts;
        }

    }

    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld %lld",&down,&up);
        sum = prime[up] - prime[down-1];
        printf("%lld\n",sum);
    }

}
