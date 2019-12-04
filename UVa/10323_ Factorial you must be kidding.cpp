#include<stdio.h>
int main()
{
    long long int fact,a,n;
    while (scanf("%lld",&n)==1)
    {
        fact=1;
        if(n>13)
        {
            printf("Overflow!\n");
        }
        else if(n<=0)
        {
            if(n%2==0)
            {
                printf("Underflow!\n");
            }
            else if(n%2!=0)
            {
                printf("Overflow!\n");
            }
            else
            {
                printf("Underflow!\n");
            }
        }
        else if(n<8)
        {
            printf("Underflow!\n");
        }
        else
        {
            for(a=1; a<=n; a++)
            {
                fact=a*fact;
            }
            printf("%lld\n",fact);
        }
    }
    return 0;
}
