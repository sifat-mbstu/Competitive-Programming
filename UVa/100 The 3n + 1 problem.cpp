#include<bits/stdc++.h>
using namespace std;
long int counts;
long int f(int N)
{
    //printf("%d \n",counts++);
    counts++;
    if(N==1){return counts;}
    if(N%2==0){return f(N/2);}
    else{return f(3*N + 1);}
}
int main()
{
    long int N,Min,Max,Res,i,j;
    //counts = 0;
    while(scanf("%ld %ld",&Min,&Max)==2){
    Res = 0;
    i = Min, j = Max;
    if(Min>Max){swap(Min,Max); }
    for(N=Min;N<=Max;N++)
        {
            counts=0;
            counts = f(N);
            if(Res<counts){Res = counts;}
        }
    printf("%ld %ld %ld\n",i,j,Res);
    }
    return 0;
}
