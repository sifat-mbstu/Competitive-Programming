#include<stdio.h>
int main()
{
    int n,Sum,t,P,Q, ara[40],i,N,k;
    scanf("%d",&N);
    for(k=1;k<=N;k++)
    {
    scanf("%d%d%d",&n,&P,&Q);
    Sum=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }
    t=0;
    i=1;
    Sum=ara[0];
    while(Q>=Sum)
    {
        if(t==P){break;}
        //printf("t=%d P=%d\n",t,P);
        if(i==n){t++;break;}
        Sum = Sum + ara[i];
        i++;
        t++;
    }
    printf("Case %d: %d\n",k,t);
    }
    return 0;
}
