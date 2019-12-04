///Accepted
#include<stdio.h>
#include<math.h>
int main()
{
    long long sum,n,a,test,i;
    long long range;

    printf("PERFECTION OUTPUT\n");
        while(scanf("%lld",&n)==1)
    {
        if(n==0){break;}
        sum=0;
        range = sqrt(n);
        for(a=1; a<=range; a++)
            {
                if((n%a)==0)
                {
                    sum=sum+a;
                    if((n/a)!=a && a!=1)
                    {
                        sum=sum+n/a;
                    }
                }
            }

            //printf("sum==%lld\n",sum);
            if(sum==n){printf("%5lld  PERFECT\n",n);}
            else if(sum>n){printf("%5lld  ABUNDANT\n",n);}
            else {printf("%5lld  DEFICIENT\n",n);}
        }
        printf("END OF OUTPUT\n");
    return 0;
}
