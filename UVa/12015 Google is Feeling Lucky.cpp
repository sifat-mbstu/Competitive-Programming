///ACCEPTED
#include<stdio.h>
#include<string.h>
int main()
{
    int ara[20],i,maxi,j=0,test;
    char str[110][20];
    scanf("%d",&test);

    while(test--)
    {
        maxi = 0;
        for(i=0;i<10;++i)
        {
            scanf("%s",str[i]);
            scanf("%d",&ara[i]);
            if(ara[i] > maxi){maxi = ara[i];}
        }

        printf("Case #%u:\n",++j);
        for(i=0;i<10;++i)
        {
            if(ara[i]==maxi)
            {
                printf("%s\n",str[i]);
            }
        }
    }
    return 0;
}
