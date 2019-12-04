#include<stdio.h>
int main()
{
    int T,i;
    long long int sum=0,num=1;
    while(num!=0)
    {
        scanf("%lld",&num);
        sum=sum+num;
    }
    printf("%lld",sum);
    return 0;
}
