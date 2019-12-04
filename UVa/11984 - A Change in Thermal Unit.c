#include<stdio.h>
int main()
{
    int n,i;
    float F,C,d,Res;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%f%f",&C,&d);
        F=((9.0/5)*C) + 32 + d;
        Res = ((F - 32)/9)*5;
        printf("Case %d: %.2f\n",i,Res);
    }
    return 0;
}
