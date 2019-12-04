#include<stdio.h>
int main()
{
    int lumber[15],N,i,res,t;
    scanf("%d",&N);
    printf("Lumberjacks:\n");
    while(N--)
    {
        for(i=0;i<10;i++)
        {
            scanf("%d",&lumber[i]);
        }

    if(lumber[0]>lumber[1]){t=0;}
    else if(lumber[0]<lumber[1]){t=1;}
    res=0;
    if(t){
        for(i=0;i<9;i++)
            {
                if(lumber[i]<lumber[i+1]){res=1;}
                else{res=0;break;}
            }
    }
    else {
        for(i=0;i<9;i++)
            {
                if(lumber[i]>lumber[i+1]){res=1;}
                else{res=0;break;}
            }
    }
    if(res){printf("Ordered\n");}
    else{printf("Unordered\n");}
    }
    return 0;
}

