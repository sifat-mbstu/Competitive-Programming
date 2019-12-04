#include<stdio.h>
#include<math.h>
int main()
{
    long long int L,U,n,a,test,i,count=0,Max_div,Max_num;
    double range;
    scanf("%lld",&test);
    for(i=1; i<=test; i++)
    {
        scanf("%lld %lld",&L,&U);
        Max_div=0;
        Max_num=0;
        for(n=L; n<=U; n++)
        {
            count=0;
            range = sqrt(n);
            for(a=1; a<=range; a++)
            {
                if((n%a)==0)
                {
                    if((n/a)!=a && a!=1)
                    {
                        count++;
                    }
                    count++;
                }
            }
            if(n>1)
            {
                count++;
            }
            if(Max_div<count)
            {
                Max_div=count;
                Max_num=n ;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",L,U,Max_num,Max_div);
    }
    return 0;
}
