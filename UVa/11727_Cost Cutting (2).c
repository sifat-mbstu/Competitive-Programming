#include<stdio.h>
int main()
{
    int i,N,a,b,c,sum,Max,Min,Mid;
    scanf("%d",&N);
    for(i=1; i<=N; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        sum=a+b+c;
        if(a>b)
        {
            Max=a , Min=b;
        }
        else
        {
            Min=a,Max=b;
        }
        if(Max<c)
        {
            Max=c;
        }
        if(Min>c)
        {
            Min=c;
        }
        Mid=sum-Max-Min;
        printf("Case %d: %d\n",i,Mid);
    }
    return 0;
}
