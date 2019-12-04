#include <stdio.h>

int main(void)
{
    unsigned long long int m,n,rem_m,rem_n,judge=0,sum,count;
    while((scanf("%llu%llu",&m,&n))==2)
    {
        if(m==0 && n==0)
        {
            break;
        }
        count=0;

        /* We want || here, not && */
        while(m!=0 || n!=0)
        {
            rem_m=m%10;
            rem_n=n%10;
            if(judge==1)
            {
                rem_m++;
            }
            sum = rem_m+rem_n;
            judge=0;
            if(sum>=10)
            {
                count++;
                judge++;
            }
            m=m/10;
            n=n/10;
        }

        /* Clean up for next iteration */
        judge = 0;

        if(count==0)
        {
            printf("No carry operation.\n");
        }
        else if(count==1)
        {
            printf("%llu carry operation.\n",count);
        }
         else
        {
            printf("%llu carry operations.\n",count);
        }

    }
    return 0;
}
