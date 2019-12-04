#include <stdio.h>
int main()
{
    int lower_range,upper_range,a,i,sum,count;
    scanf("%d",&count);
    for(i=1; i<=count; i++)
    {
        sum=0;
        scanf("%d",&lower_range);
        scanf("%d",&upper_range);
        for(a=lower_range; a<=upper_range; a++)
        {
            if((a%2)!=0)
            {
                sum=sum+a;
            }
        }
        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}
