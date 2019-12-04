#include <stdio.h>
int main()
{
    int i,j,k,n,N,up,down;
    int Wall[50];
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        up=0,down=0;
        scanf("%d",&N);
        for(k=0; k<N; k++)
        {
            scanf("%d",&Wall[k]);
        }
        for(j=0; j<N-1; j++)
        {
            if(Wall[j]<Wall[j+1])
            {
                up++;
            }
            else if ( Wall[j]==Wall[j+1])
            {}
            else
            {
                down++;
            }
        }
        printf("Case %d: %d %d\n",i,up,down);
    }
    return 0;
}


