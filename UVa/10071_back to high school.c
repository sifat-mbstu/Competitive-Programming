#include<stdio.h>
int main()
{
    int v,t,displacement;
    while((scanf("%d %d",&v,&t))==2)
    {
        displacement=2*v*t;
        printf("%d\n",displacement);
    }
    return 0;
}
