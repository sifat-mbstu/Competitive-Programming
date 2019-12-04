#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int a,b,diff;
    while(scanf("%d%d",&a,&b)==2)
    {
        if(a==-1 && b==-1){break;}
        diff=abs(a-b);
        if(diff>50){diff=100-diff;}
        printf("%d\n",diff);
    }
    return 0;
}

