#include<stdio.h>
int main()
{
    int i,a,b,test,rem_a,rem_b,multi;
    scanf("%d",&test);
    for(i=0;i<test;i++){
            multi=1;
    scanf("%d%d",&a,&b);
    rem_a=a/3;
    rem_b=b/3;
    multi=rem_a*rem_b;
    printf("%d\n",multi);
    }
    return 0;
}
