#include<stdio.h>
int main()
{
    int N,p,q,j,sum,cola;
    while(scanf("%d",&N)==1)
    {
        sum=0;
        cola=N;
        j=N;
        p=0;
        while(j>=3)
        {
            N=j/3;
            q=j%3;
            j=N+q;
            p=p+N;
        }
    if(j==2)
        {
            p++;
        }
        sum = p + cola;
        printf("%d\n",sum);
    }
    return 0;
}
