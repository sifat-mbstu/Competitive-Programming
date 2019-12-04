#include<stdio.h>
int main()
{
    long long int a,b,c,d,n;
    while((scanf("%lld",&n))==1 && n>=0){
    b=1;
    for(a=1;a<=n;a++)
    {
        b=b+a;
    }
    printf("%lld\n",b);
    }
    return 0;
}
