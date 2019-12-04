#include <stdio.h>
int main()
{
    int N,i,a,ara[100],ori,test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&N);
        for(i=0; i<=9; i++)
        {
            ara[i]=0;
        }
        for(i=1; i<=N; i++)
        {
            if(i<10)
            {
                ara[i]=1;
            }
            else
            {
                ori=i;
                while(ori!=0)
                {
                    a=ori%10;
                    ara[a]=ara[a]+1;
                    ori=ori/10;
                }
            }
        }
        for(i=0; i<=9; i++)
        {
            if(i<9)
            printf("%d ",ara[i]);
            else
                printf("%d\n",ara[i]);
        }
    }
    return 0;
}
