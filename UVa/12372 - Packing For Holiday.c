#include<stdio.h>
int main()
{
    int N,a,b,c,i;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a<=20 && b<=20 && c<=20)
        {
            printf("Case %d: good\n",i);
        }
        else{printf("Case %d: bad\n",i);}
    }
    return 0;
}
