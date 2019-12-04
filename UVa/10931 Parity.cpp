#include<stdio.h>
int main()
{
    int num,i,n,counts,T,j;
    int a[240];

        while(scanf("%d",&num)==1 && num !=0)
        {
        counts=0;
        n=0;
        while(num>0)

        {
            a[n]=num%2;
            num=num/2;
            n++;
        }
        printf("The parity of ");
        for(i=n-1; i>=0; i--)
        {
            printf("%d",a[i]);
            if (a[i] % 2!=0 )
            {
                counts++;
            }
        }
        printf(" is %d (mod 2).\n",counts);
    }
    return 0;
}
