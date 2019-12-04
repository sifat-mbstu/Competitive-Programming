#include<stdio.h>
int main()
{
    unsigned long long int N,Q,ara_N[99999],i,j,height,x,y;
    scanf("%llu",&N);
    int t=0;
    for(i=0;i<N;i++)
    {
        scanf("%llu",&ara_N[i]);
        if(i>0 && ara_N[i]!=ara_N[i-1]){t=1;}
    }
    scanf("%llu",&Q);

    for(i=0;i<Q;i++)
    {
        scanf("%llu",&height);
        if(t){
        if(height < ara_N[0]){printf("X %llu\n",ara_N[0]);}
        else if(height == ara_N[0])
            {
                x=1;
                while(ara_N[x]==height){x++;}
                printf("X %llu\n",ara_N[x]);
            }
        else if(height == ara_N[N-1])
            {
                x = N-2;
                while(ara_N[x]==height){x--;}
                printf("%llu X\n",ara_N[x]);
            }
        else if(height > ara_N[N-1]){printf("%llu X\n",ara_N[N-1]);}
        else
        {for(j=0;j<N;j++)
        {
            if(ara_N[j]>=height)
                {
                    if(ara_N[j]==height)
                    {
                        x =j-1;
                        y =j+1;
                        while(ara_N[x]==height){x--;}
                        while(ara_N[y]==height){y++;}
                        printf("%llu %llu\n",ara_N[x],ara_N[y]);
                        break;
                    }
                    else
                    {
                            x = j - 1;
                            while(ara_N[x]==height){x--;}
                            printf("%llu %llu\n",ara_N[x],ara_N[j]);
                            break;
                    }
                }
        }
        }
        }
        else{printf("X X\n");}
    }
}
