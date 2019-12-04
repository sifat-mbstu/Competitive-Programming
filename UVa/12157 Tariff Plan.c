#include<stdio.h>
int main()
{
    int N,test,time,Juice_sum ,Mile_sum ,i,a,b,x;
    scanf("%d",&test);
    for(x=1;x<=test;x++)
    {
    Juice_sum = Mile_sum=0;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&time);
        a=(time+1)/30;
        if(a*30 != (time + 1)) {a++;}
        Mile_sum = Mile_sum + a*10;

        b=(time+1)/60;
        if(b*60 != (time + 1)) {b++;}
        Juice_sum = Juice_sum + b*15;
    }
    if(Juice_sum < Mile_sum){printf("Case %d: Juice %d\n",x,Juice_sum);}
    else if(Juice_sum > Mile_sum){printf("Case %d: Mile %d\n",x,Mile_sum);}
    else {printf("Case %d: Mile Juice %d\n",x,Mile_sum);}
    //printf("%d\n",Mile_sum);
    //printf("%d\n",Juice_sum);
    }
    return 0;
}
