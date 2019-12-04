#include<stdio.h>
int main()
{
    int N,a,d,result,i,count,test;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d",&N);
        a=((N*567)/9+7492)*235;
        result=a/47-498;
        count=0;
        while(count!=2)
        {
            count++;
            d=result%10;
            result=result/10;
        }
        if(d>=0)
        {
            printf("%d\n",d);
        }
        else
        {
            printf("%d\n",0-d);
        }
    }
    return 0;
}
