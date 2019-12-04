#include<stdio.h>
int main()
{
    long long int N;
    long long i,p,a[100];
    while (scanf("%lld",&N) && N>0)
    {
        i=0;
        while (N!=0)
        {
            a[i]=N%3;
            i++;
            N=N/3;
        }
        for(p=i-1; p>=0; p--)
        {
            printf("%lld",a[p]);
        }
        printf("\n");
    }
    return 0;
}
