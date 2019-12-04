#include<stdio.h>
int main()
{
    long long int a, b, c, n, count, ara[1005];
    while(scanf("%lld", &n)==1)
    {
        count = 0;
        for(a=0; a<n; a++)
        {
            scanf("%lld", &ara[a]);
        }
        for(a=1; a<n; a++)
        {
            for(b=n-1; b>=a; b--)
            {
                if(ara[b-1] > ara[b])
                {
                    c = ara[b-1];
                    ara[b-1] = ara[b];
                    ara[b] = c;
                    count++;
                }
            }
        }
        printf("Minimum exchange operations : %lld\n", count);
    }
    return 0;
}
