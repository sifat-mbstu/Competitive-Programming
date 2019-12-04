#include<stdio.h>
#include<math.h>
int main()
{
    double ara[10],a,ara_1[10];
    int i,j;
    while(scanf("%lf%lf%lf",&ara[0],&ara[1],&ara[2])==3)
    {
        if(ara[0]==0 && ara[1]==0 && ara[2]==0 )
        {
            break;
        }
        for(i=0; i<3; i++)
        {
            for(j=i+1; j<3; j++)
            {
                if(ara[i]<ara[j])
                {
                    a=ara[j];
                    ara[j]=ara[i];
                    ara[i]=a;
                }
            }
        }
        for(i=0; i<3; i++)
        {
            ara_1[i]=pow(ara[i],2);
        }
        if(ara_1[0]==ara_1[1]+ara_1[2])
        {
            printf("right\n");
        }
        else
        {
            printf("wrong\n");
        }
    }
    return 0;
}
