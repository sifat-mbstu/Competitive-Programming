#include <stdio.h>
int main()
{
    int T,N,para,days[10000],i,k,sum,count,Num_of_party;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        scanf("%d",&Num_of_party);

        for(i=0; i<N; i++)
        {
            days[i]=0;
        }
        for(k=0; k<Num_of_party; k++)
        {
            count=sum=0;
            scanf("%d",&para);


            while(sum<=N)
            {
                sum=sum+para;
                if(sum>N)
                {
                    break;
                }
                // printf("sum=%d\n",sum);
                if(days[sum-1]==0)
                {
                    if(((sum+1)%7)!=0 && (sum%7)!=0)
                    {
                        days[sum-1]++;
                        //printf("Hartal Days=%d and value = %d\n",sum,days[sum-1]);
                    }
                }
            }
        }
        for(i=0; i<N; i++)
        {
            if(days[i]!=0)
            {
                //printf("days==%d\n",i+1);
                count++;
            }

        }
        printf("%d\n",count);
    }
    return 0;
}
