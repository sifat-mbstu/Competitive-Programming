#include<stdio.h>
int main()
{
    int c[10000];
    int i, j, k, l, n, max, num;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        max = 0;
        scanf("%d", &j);
        for(k=0; k<j; k++)
        {
            scanf("%d", &num);
            if(max<num)
            {
                max = num;
            }
        }
        printf("Case %d: %d\n", i, max);
    }
    return 0;
}
