#include<stdio.h>
int main()
{
    long long int a,Num,Min,Max,M,Num1,i,j,Count,Res;
    while(scanf("%lld %lld",&Min,&Max)==2)
    {
        if(Min>Max){a=Min;Min=Max;Max=a;}
        if(Min==0 && Max==0)
        {
            break;
        }
        M=0;
        for(i=Min; i<=Max; i++)
        {
            Count =0;
            if(i==1){M=3;Res=i;}
            else{
            Num=i;
            Num1=i;
            while(Num1!=1)
            {
                if(Num1%2==0)
                {
                    Num1=Num1/2;
                }
                else
                {
                    Num1=3*Num1+1;
                }
                Count++;
            }
            if(M<Count)
            {
                M=Count;
                Res=Num;
            }
            }
        }

        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",Min,Max,Res,M);
    }
    return 0;
}
