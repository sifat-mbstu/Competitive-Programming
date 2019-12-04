#include <stdio.h>
int main()
{
    int sum,N,T,P,i,j,k,Hartal;
    int party [110];
    scanf("%d",&T);
    for(i=0; i<T; i++)
    {
        sum=0;
        scanf("%d",&N);
        scanf("%d",&P);
        for(j=0; j<P; j++)
        {
            scanf("%d",&party[j]);
            Hartal = N/party[j];
            printf("Hartal = N/party[j] = %d\n\n",Hartal);
            for(k=6; k<=N; k+=7)
            {
                if(k%party[j]==0 && k>=party[j])
                {
                    Hartal-- ;            printf("Hartal-- = %d  ",Hartal);
                }
                printf("%d\n",Hartal);
            }
            sum=sum+Hartal;            printf("sum=sum+Hartal = %d\n",sum);
        }
        printf("%d\n",sum);
    }
    return 0;
}
