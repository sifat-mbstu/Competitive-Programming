#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *park,n,max,min,i,result,test;
    scanf("%d",&test);
    while(test--)
    {
        result=0;
        max=0;
        min=100;
        scanf("%d",&n);
        park=(int *) malloc(n*sizeof(int));
        for(i=0; i<n; i++)
        {
            scanf("%d",&park[i]);
        }
        for(i=0; i<n; i++)
        {
            if(max<park[i])
            {
                max=park[i];
            }
            if(min>park[i])
            {
                min=park[i];
            }
        }
        result = (max-min)*2;
        printf("%d\n",result);
    }
    return 0;
}
