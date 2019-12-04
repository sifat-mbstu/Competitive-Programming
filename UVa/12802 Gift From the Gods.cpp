#include<bits/stdc++.h>
using namespace std;
#define SIZE 1010000

long long int status[SIZE];
void sieve()
{
    long long int i,j;
    for(i=0; i<SIZE; i++) status[i]= 0;
    long int sq = sqrt(SIZE);
    for(i=4; i<=SIZE; i+=2) status[i] = 1;
    for(i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for(j=2*i; j<=SIZE; j+=i) status[j]=1;
        }
    }
    status[1] = 0;
}
int main()
{
    long long int Num,sum,cpy,a;
        sieve();

    while(scanf("%lld",&Num)==1)
    {
    printf("%lld\n",Num*2);
    if(status[Num]==0)
    {
      //  printf("status[Num]=%ld Num=%ld",status[Num],Num);
    cpy = Num;
    sum = 0;
        while(Num!=0)
        {
            a=Num%10;
            sum = sum*10 + Num%10;
            Num = Num / 10;
        }
        if(sum == cpy){break;}
    }
    }
}
