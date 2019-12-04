#include<stdio.h>
int main()
{
    unsigned long long sum,n,x;
    while(scanf("%llu",&sum)==1)
    {
        if(sum==0)break;
        x=(sum*10)/9;
        if(sum%9==0)printf("%llu %llu\n",x-1,x);
        else printf("%llu\n",x);
    }
    return 0;
}
