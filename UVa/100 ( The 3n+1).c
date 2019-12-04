#include<stdio.h>
int main()
{
    long int i,j,max,min,MAX,n,count,x;
    while(scanf("%ld %ld",&i,&j)==2)
    {
        MAX=0;
        if(i<=j)
        {
            max=j,min=i;
        }
        else
        {
            max=i;
            min=j;
        }
        for(n=max; n>=min; n--)
        {
            x=n;
            count=1;
            while(x!=1)
            {
                count++;
                if(x%2==0)
                {
                    x=x/2;
                }
                else
                {
                    x=3*x+1;
                }
            }
            if(count>MAX)
            {
                MAX=count; //printf("n-%d\n",n);
            }
        }
        printf("%ld %ld %ld\n",i,j,MAX);
    }
    return 0;
}
