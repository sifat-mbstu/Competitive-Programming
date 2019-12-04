#include<stdio.h>
int main()
{
    int a,b,i,j,n,sum;
    scanf("%d",&n);
    for(j=1; j<=n; j++)
    {
        scanf("%d%d",&a,&b);
        sum=0;
        for(i=a; i<=b; i++)
        {
            if(i%2!=0)
            {
                sum=sum+i;
            }
        }
        printf("Case %d: %d\n",j,sum);
    }
    return 0;
}
