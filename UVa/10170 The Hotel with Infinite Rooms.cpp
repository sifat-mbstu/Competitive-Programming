#include<stdio.h>
int main()
{
    long long int sum,S,D;
    while(scanf("%lld %lld",&S,&D)==2)
    {
        sum=0;
        while(sum<D)
        {
            sum=sum+S;
            S++;
        }
        printf("%lld\n",S-1);
    }
    return 0;
}
