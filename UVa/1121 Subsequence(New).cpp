#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,ara[100000],sum,j,N,S;
    while(scanf("%lld %lld",&N, &S)==2)
    {
    for(i=0; i<N; i++)
    {
        scanf("%lld",&ara[i]);
    }
    sum = j=0;
    sort(ara, ara+N);
    for(i=N-1; i>=0; i--)
    {
        sum += ara[i];
        j++;
        if(sum >= S){break;}
    }
    printf("%lld\n",j);
    }
}
