#include<stdio.h>
int main()
{
    int sim[1000],Case,Col,i,a,b,j,res;
    scanf("%d",&Case);
    while(Case--)
    {
        i=0;
        scanf("%d",&Col);
        while(Col--){
        scanf("%d%d",&a,&b);
        sim[i] = a - b;
        i++;
        }
        for(j=1;j<i;j++)
            {
                if(sim[j]!=sim[j-1])
                {
                    res=0;
                    break;
                }
                else{res=1;}
            }
        if(res){printf("yes\n");}
        else{printf("no\n"); }
        if(Case){printf("\n");}
    }
    return 0;
}
