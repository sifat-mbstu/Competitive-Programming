#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll cases,ara[510],r,i,sum,mid,dif;
    scanf("%lld",&cases);
    while(cases--){
    scanf("%lld",&r);
    sum =0;
    for(i=0;i<r;i++)
    {
        scanf("%lld",&ara[i]);
    }
    sort(ara,ara+r);

    mid = ((r+1)/2)-1;
    //printf("mid = %lld ara[mid] = %lld\n",mid,ara[mid]);
    for(i=0;i<r;i++)
    {
        dif = abs(ara[mid] - ara[i]);
        //printf("mid = %lld \n",mid);
        sum = sum + dif;
        //printf("sum = %lld\n",sum);
    }
    printf("%lld\n",sum);
    }
}
