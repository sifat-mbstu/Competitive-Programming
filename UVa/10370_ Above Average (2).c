#include<stdio.h>
int main()
{
    float b,test,sum,n,count,avg,ans;
    int a,Student_count[1005];
    scanf("%f",&test);
    for(b=1; b<=test; b++)
    {
        scanf("%f",&n);
        sum=0,count=0;

        for(a=0; a<n; a++)
        {
            scanf("%d",&Student_count[a]);
            sum=sum+Student_count[a];
        }
        avg=sum/n;
        for(a=0; a<n; a++)
        {
            if(Student_count[a]>avg)
            {
                count++;
            }
        }
        ans=(count/n)*100;
        printf("%.3f%\n",ans);
    }
    return 0;
}
