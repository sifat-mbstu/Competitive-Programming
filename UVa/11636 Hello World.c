#include<stdio.h>
int main()
{
    int num,case1=0,count,sum;
    while((scanf("%d",&num)==1))
    {
        if(num<0)
        {
            break;
        }
        count=0,sum=1;
        while(sum<num)
        {
            sum=sum*2;
            count++;
        }
        if(sum<num)
        {
            count++;
        }
        case1++;
        printf("Case %d: %d\n",case1,count);
    }
}
