#include <stdio.h>
int main()
{
    unsigned long long int N,sum,a,Num;
    while((scanf("%llu",&N))==1){
        if(N==0){break;}
    sum=0;
    while(N!=0)
    {
        a=N%10;
        sum=sum+a;
        N=N/10;
        if(N==0 && sum>=10)
        {
            N=sum;
            sum=0;
        }
    }
    printf("%llu\n",sum);
    }
    return 0;
}
