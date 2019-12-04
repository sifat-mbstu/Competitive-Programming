#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int k,n,i,ara[15],j,t=0;

    while(scanf("%lld",&n)==1){
            t++;
    for(i=0;i<11;i++)
    {
        ara[i] = 0;
    }
    i=0;
    while(n!=0)
    {
        if(i==0 || i==2 || i==3 || i==4 || i==6 || i==7){ara[i] = n % 100; n = n/100;}
        else if(i==1 || i==5 || i==8){ara[i] = n % 10; n = n/10;}
        i++;
        //printf("n = %lld\n",n);
    }
    printf("%4lld. ",t);
    for(j=i-1;j>=0;j--)
        {
            if(ara[j]>0){
                printf("%lld",ara[j]);
                 if(j!=0)printf(" ");
            }
            if(j==8 && ara[j]>0){printf("kuti ");}
            else if(j==7 && ara[j]>0){printf("lakh ");}
            else if(j==6 && ara[j]>0){printf("hajar ");}
            else if(j==5 && ara[j]>0){printf("shata ");}
            else if(j==4 && j!=-1 && ara[j]>0){printf("kuti ");}
            else if(j==3 && ara[j]>0){printf("lakh ");}
            else if(j==2 && ara[j]>0){printf("hajar ");}
            else if(j==1 && ara[j]>0){printf("shata");if(ara[0]!=0){printf(" ");}}
        }
    printf("\n");
    }
}
