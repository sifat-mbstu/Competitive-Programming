#include<stdio.h>
int main()
{
    unsigned long long int h,Count,total,total_1,sum,N,i,c,b,k,a,ar[100],real,test;
    scanf("%llu",&test);
    for(h=0; h<test; h++)
    {
        k=10,sum=Count=0;
        scanf("%llu",&N);
        while(k==10)
        {
            Count++;
            real=N;
            while(N!=0)
            {
                a=N%10;
                sum=sum*10+a;
                N=N/10;
            }
            total=sum+real;
            total_1=total;

            for(i=0; total!=0; i++)
            {
                ar[i]=total%10;
                total=total/10;
            }
            i--;
            k=0;
            for(c=0,b=i; c<i/2,b>i/2; c++,b--)
            {
                if(ar[c] !=ar[b])
                {
                    k=10;
                    break;
                }
            }
            if(k==10)
            {
                N=total_1,sum=0;
            }
            else
            {
                printf("%llu %llu\n",Count,total_1);
            }
        }
    }
    return 0;
}
