#include<bits/stdc++.h>
using namespace std;

int main()

{
    int t,sum1=0;
    float a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
        int cond = 0;
        sum1 ;
        scanf("%f %f %f %f",&a,&b,&c,&d);
        float sum = a+b+c;
         if(((a<=56&&b<=45&&c<=25)||(a+b+c<=125))&&d<=7)
        {
            cond = 1;
            sum1++;
        }
        printf("%d\n",cond);
    }
    printf("%d\n",sum1);
}
