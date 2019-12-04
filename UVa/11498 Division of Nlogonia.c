#include<stdio.h>
#include<stdlib.h>
int main()
{
    int N,M,X,Y,test,test1;
    while((scanf("%d",&test))==1)
    {
        if(test==0)
        {
            exit(0);
        }
        test1=test;
        while(test--)
        {
            if((test+1)==test1)
            {
                scanf("%d%d",&N,&M);
            }
            scanf("%d%d",&X,&Y);
            X=X-N;
            Y=Y-M;
            if(X==0 || Y==0)
            {
                printf("divisa\n");
            }
            else if(X>0 && Y>0)
            {
                printf("NE\n");
            }
            else if(X<0 && Y>0)
            {
                printf("NO\n");
            }
            else if(X<0 && Y<0)
            {
                printf("SO\n");
            }
            else
            {
                printf("SE\n");
            }
        }
    }
    return 0;
}
