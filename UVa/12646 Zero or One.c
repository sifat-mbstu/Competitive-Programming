#include<stdio.h>
int main()
{
    int A,B,C;
    while(scanf("%d%d%d",&A,&B,&C)==3)
    {
        if((A==0 && (B+C)==2) ||(A==1 && (B+C)==0)){printf("A\n");}
        else if((B==0 && (A+C)==2) ||(B==1 && (A+C)==0)){printf("B\n");}
        else if((C==0 && (A+B)==2) ||(C==1 && (A+B)==0)){printf("C\n");}
        else {printf("*\n");}
    }
    return 0;
}
