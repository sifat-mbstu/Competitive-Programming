#include<stdio.h>
int main()
{
    long long int y,count;
    while(scanf("%lld", &y)==1)
    {
        count=0;
        if(y>=2000)
        {
            if((y%4==0) && ((y%100!=0) || (y%400==0)))
            {
                printf("This is leap year.\n");
                count++;
            }
            if(y%15==0)
            {
                printf("This is huluculu festival year.\n");
                count++;
            }
            if ((y%55==0) && ((y%4==0) && ((y%100!=0) || (y%400==0))))
            {
                printf("This is bulukulu festival year.\n");
                count++;
            }

            if(count==0)
            {
                printf("This is an ordinary year.\n");
            }
        }
        printf("\n");
    }
    return 0;
}
