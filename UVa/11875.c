#include <stdio.h>
int main()
{
    int pla[20];
    int i,j,k,test,N,a,l;
    scanf("%d",&test);
    for(l=1; l<=test; l++)
    {
        scanf("%d",&N);
        for(i=0; i<N; i++)
        {
            scanf("%d",&pla[i]);
        }
        for(i=0; i<N; i++)
        {
            for(j=i+1; j<N; j++)
            {
                if(pla[j]<pla[i])
                {
                    a=pla[i];
                    pla[i]=pla[j];
                    pla[j]=a;
                }
            }
        }
        k=(N+1)/2;
        printf("Case %d: %d\n",l,pla[k-1]);
    }
    return 0;
}
