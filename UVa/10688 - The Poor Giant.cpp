#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int main()

{
    int n,k,ara[1000],Small,res[1000],i,j,x,sum;
    scanf("%d%d",&n,&k);

    for(i=1;i<=n;i++)
    {
        ara[i-1]=i+k;
        x=0;
        printf("ara==%d\n",ara[i-1]);
    }
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<n;j++)
        {
            sum=sum+ara[x];
        printf("sum=%d\n",sum);
        if(i==x && i!=n){x+=2;sum++;}
        res[i]=sum;
        }
        x=0;
        printf("\n..............\n");
    }
    for(i=0;i<n;i++){
        printf("%d ",res[i]);
    }
    Small=min(res[0],res[n]);
    printf("\n%d",Small);

    return 0;
}
