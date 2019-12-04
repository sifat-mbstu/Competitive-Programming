#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int *given,*ara,test,temp,jolly,i,j,k,N;
    while(scanf("%d",&N)==1)
    {
        given = (int *) malloc(N*sizeof(int));
        ara = (int *) malloc(N*sizeof(int));
        for(i=0; i<N; i++)
        {
            scanf("%d",&given[i]);
        }
        for(i=0; i<N-1; i++)
        {
            ara[i]=abs(given[i]-given[i+1]);
        }
        for(i=0; i<N-1; i++)
        {
            for(j=i+1; j<N-1; j++)
            {
                if(ara[i]>ara[j])
                {
                    temp = ara[i];
                    ara[i] = ara[j];
                    ara[j] =temp;
                }
            }
        }
        /*
                for(i=0;i<N-1;i++){
                    printf("%d ",ara[i]);
                }
                printf("\n");
        */
        if(N==1)
        {
            jolly = 1;
        }
        else if(N==2 && ara[i]==1)
        {
            jolly == 1;
        }
        else if(N>2)
        {
            if(ara[0]==1)
            {
                for(i=0; i<N-2; i++)
                {
                    if(ara[i+1]==ara[i]+1)
                    {
                        jolly = 1;
                    }
                    else
                    {
                        jolly=0;
                        break;
                    }
                }
            }
            else if(ara[N-2] ==1)
            {
                for(i=N-2; i>0; i--)
                {
                    if((ara[i]+1)==ara[i-1])
                    {
                        jolly = 1;
                    }
                    else
                    {
                        jolly = 0;
                        break;
                    }
                }
            }
            else
            {
                jolly =0;
            }
        }
        if(jolly)
        {
            printf("Jolly\n");
        }
        else
        {
            printf("Not jolly\n");        }
        }
    return 0;
}
