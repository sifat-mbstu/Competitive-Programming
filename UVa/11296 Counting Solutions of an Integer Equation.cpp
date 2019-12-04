#include <stdio.h>
#define ll unsigned long long
#define maxx 1000001
ll ara[maxx][5];
int main()
{
    ll n,x,i,j;
    for(i = 0; i < 5; i++)
    {
        ara[0][i] = i;
    }
    ll sum = 0;
    for(i = 1; i < maxx; i++)
    {
        sum = 0;
        for(j = 0; j < 5; j++)
        {
            sum += ara[i-1][j];
            //printf("sum = %llu\n\n",sum);
            ara[i][j] = sum;
        }
    }
    while(scanf("%llu",&n)==1){
    i = n/2;
    if(i < 1) i = 1;
    if(n!=0 && n!=1) printf("%llu\n",ara[i-1][3]);
    else printf("1\n");
    }
    return 0;
}
