#include<stdio.h>
int main()
{
    int a,b,c,N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(c>=(a+b) || b>=(a+c) || a>=(b+c)){printf("Wrong!!\n");}
            else{printf("OK\n");}
        }
        return 0;
}
