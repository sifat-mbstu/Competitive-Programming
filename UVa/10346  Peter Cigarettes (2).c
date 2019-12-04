#include<stdio.h>
int main()
{
    int n, k, d,t,i;
    int a[1000];
    while((scanf("%d",&t))==1)
    {
        for(i=0; i<t; i++)
        {
            scanf("%d %d", &n, &k);
            a[i] = n;
            while(d>0)
            {
                d=n / k;
                a[i]= a[i]+d;
                if(d<k)
                {
                    break;
                }
                n=d + (n%k);
            }
        }
        for(i=0; i<t; i++)
        {
            printf("%d\n",a[i]);
        }
    }
    return 0;
}
