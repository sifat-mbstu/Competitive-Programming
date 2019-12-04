#include<stdio.h>
int main()
{
    int a,b,m,n,rem_m,rem_n,judge=0,sum,count;
    while((scanf("%d%d",&m,&n))==2)
    {
        sum = judge =0;
        if(m==0 && n==0)
        {
            break;
        }
        count=0;
        while(m!=0 || n!=0)
        {
            rem_m=m%10;
            rem_n=n%10;
            if(judge==1)
            {
                rem_m++;
            }
            sum = rem_m+rem_n;
            //printf("rem_m == %d rem_n== %d sum == %d\n",rem_m, rem_n, sum);
            judge=0;
            if(sum>9)
            {
                count++;
                judge++;
            }
            m=m/10;
            n=n/10;
        }
        if(count==0)
        {
            printf("No carry operation.\n");
        }
        else if(count==1)
        {
            printf("%d carry operation.\n",count);
        }
        else
        {
            printf("%d carry operations.\n",count);
        }
    }
    return 0;
}

