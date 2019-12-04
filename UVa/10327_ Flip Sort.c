#include<stdio.h>
int main()
{
    int i,j,n,count,t;
    int ex[1000];
    while(scanf("%d",&n)==1)
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&ex[i]);
        }
        count =0;
        for(i=1; i<n; i++)
        {
            for(j=n-1; j>=i; j--)
            {
                if(ex[j-1]>ex[j])
                {
                    t = ex[j-1];
                    ex[j-1] = ex[j];
                    ex[j]=t;
                    count++;
                }
            }
        }
        printf("Minimum exchange operation : %d\n",count);
    }
}
