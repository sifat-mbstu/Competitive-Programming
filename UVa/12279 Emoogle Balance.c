#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *treat,N,ff,i,treats,reason,Case=0,Result;
    while((scanf("%d",&N))==1 && N!=0)
    {
        Case++;
    treats=reason=0;
    treat=(int *) malloc(N*sizeof(int));
    for(i=0;i<N;i++)
    {
        scanf("%d",&treat[i]);
        if(treat[i]==0){treats++;}
        else {reason++;}
    }
    Result = reason - treats;
    printf("Case %d: %d\n",Case,Result);
    }
}
