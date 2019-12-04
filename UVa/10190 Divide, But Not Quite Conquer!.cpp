#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[2000000];
int main()
{
    ll n,m, i,j,k;
    bool boring;
    while(scanf("%lld %lld",&n, &m) == 2)
    {
        if(n == 0 || n==1 || m == 0 || m ==1){boring = 1;}
        else{boring = 0;
        ara[1] = n;
        for(i=2; ; i++)
        {
            if(ara[i-1] == 1)
            {
                break;
            }
            if(ara[i-1] % m == 0)
            {
                ara[i] = ara[i-1] / m;
            }
            else
            {
                boring = 1;
                break;
            }
        }
        }
        if(boring)
        {
            printf("Boring!\n");
        }
        else
        {
            printf("%lld",ara[1]);
            for(j=2; j<i; j++)
            {
                printf(" %lld",ara[j]);
            }
            printf("\n");
        }

    }
}
