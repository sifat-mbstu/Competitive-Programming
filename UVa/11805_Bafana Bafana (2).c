#include<stdio.h>
int main()
{
    int i,M,N,K,P,test,who_give;
    scanf("%d",&test);
    for(i=1; i<=test; i++)
    {
        scanf("%d %d %d",&N,&K,&P);
        if(P>N)
        {
            P=P%N;
        }
        M=K+P;
        if(M<=N)
        {
            who_give=M;
        }
        else
        {
            who_give=M-N;
        }
        printf("Case %d: %d\n",i,who_give);
    }
    return 0;
}
