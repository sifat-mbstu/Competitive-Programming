#include <stdio.h>
int main()
{
    int i,test,m,j,N,k,l;
    while((scanf("%d",&test))==1)
    {
        for(m=1; m<=test; m++)
        {
            scanf("%d%d",&N,&k);
            for(l=1; l<=k; l++)
            {
                for(i=1; i<=N; i++)
                {
                    for(j=1; j<=i; j++)
                    {
                        printf("%d",i);
                    }

                    printf("\n");
                }
                for(i=N-1; i>0; i--)
                {
                    for(j=i; j>0; j--)
                    {
                        printf("%d",i);
                    }
                    printf("\n");
                }
                if(m!=test || l!=k){printf("\n");}
            }
        }
    }
    return 0;
}
