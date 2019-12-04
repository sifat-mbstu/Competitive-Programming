#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ara[10050],j,test,ara_2[10050],t=0,i,N,Q,top,item,mid;
    while(scanf("%d %d",&N,&Q)==2)
    {

        if(N==0 && Q==0)
        {
            break;
        }
        t++;
        for(i=0; i<N; i++)
        {
            scanf("%d",&ara[i]);
        }
        sort(ara,ara+N);

        for(i=0; i<Q; i++)
        {
            scanf("%d",&ara_2[i]);
        }
        printf("CASE# %d:\n",t);

        for(i=0;i<Q;i++)
        {
            test=0;
            for(j = 0; j<N ;j++ )
            {
                if(ara[j] == ara_2[i])
                {
                    printf("%d found at %d\n",ara_2[i],j+1);
                    test = 1;
                    break;
                }
            }
            if(test==0){printf("%d not found\n",ara_2[i]);}
        }

    /*  for(i=1; i<=Q; i++)
        {
            item = ara_2[i-1];
            int bottom = 1;
            top = N;

            do
            {
                mid = (bottom + top) / 2;
                if (item < ara[mid])
                    top = mid - 1;
                else if (item > ara[mid])
                    bottom = mid + 1;
            }
            while (item != ara[mid] && bottom <= top);

            if (item == ara[mid])
            {
                while(ara[mid]==ara[mid-1])
                {
                    mid--;
                }
                //printf("Binary search successfull!!\n");
                printf("%d found at %d\n",item, mid + 1);
            }
            else
            {
                printf("%d not found\n",item);
            }
        }*/
    }
    return 0;
}
