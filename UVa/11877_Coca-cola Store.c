#include<stdio.h>
int main()
{
    int N,p,j,q;
    while(scanf("%d",&N)==1)
    {
        if(N==0)
        {
            break;
        }
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
        printf("%d\n",p);
    }
    return 0;
}
