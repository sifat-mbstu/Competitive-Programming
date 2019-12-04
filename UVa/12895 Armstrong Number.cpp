///Armstrong Number
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int ara[20],Test,i,j;
    double num;
    scanf("%d",&Test);
    while(Test--){
    unsigned long long N,N1,sum;
    scanf("%llu",&N);
    sum=0;
    N1 = N;
    i=0;
    while(N1!=0)
    {
        ara[i] = N1 % 10;
        N1 = N1 / 10;
        i++;
    }
    for(j=0;j<i;j++)
    {
        num = pow(ara[j],i);
        sum = sum + num;
    }
    //printf("Sum = %d",sum);
    if(sum==N){printf("Armstrong\n");}
    else {printf("Not Armstrong\n");}
    }
    return 0;
}
