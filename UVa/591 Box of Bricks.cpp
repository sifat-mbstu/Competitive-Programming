#include<bits/stdc++.h>
using namespace std;
int main()
{
    int counts,*ara,N,t,i,j,sum,sets=0;
    while(scanf("%d",&N)==1)
    {
        if(N==0)
        {
            break;
        }
        ara = (int *) malloc(N*sizeof(int));
        sum = counts = 0;
        for(i=0; i<N; i++)
        {
            scanf("%d",&ara[i]);
            sum = sum + ara[i];
        }
        //printf("%d",sum);
        int Div = sum / N;
        //printf("\ndiv =%d\n",Div);
        for(i=0; i<N; i++)
        {
            if(ara[i]<Div)
            {
                while(ara[i]<Div)
                {
                    for(j=i+1; j<N; j++)
                    {
                        //if(ara[j]>Div){
                        while(ara[j]>Div && ara[i]<Div)
                        {
                            ara[j]--;
                            ara[i]++;
                            counts++;
                        }
                        //}
                        if(ara[i]==Div)
                        {
                            break;
                        }
                    }
                    if(ara[i]==Div)
                    {
                        break;
                    }
                }
                //  printf("%d\n",ara[i]);
            }
            else if (ara[i]>Div)
            {
                while(ara[i]>Div)
                {
                    for(j=i+1; j<N; j++)
                    {
                        //if(ara[j]>Div){
                        while(ara[j]<Div && ara[i]>Div)
                        {
                            ara[j]++;
                            ara[i]--;
                            counts++;
                        }
                        //}
                        if(ara[i]==Div)
                        {
                            break;
                        }
                    }
                    if(ara[i]==Div)
                    {
                        break;
                    }
                }
            }
        }
        /* for(i=0; i<N; i++)
         {
             //    printf("\nara[i]%d\n",ara[i]);
             sum = sum + ara[i];
         }*/
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",++sets,counts);
    }
}
