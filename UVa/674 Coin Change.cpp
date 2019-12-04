/// Ingenuous Cubrency
#include<bits/stdc++.h>
using namespace std;

long long int arr[30];
long long int DP[100][10000];
long long int coin( long long int m, long long int n)
{

    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    if (m <= 0 && n > 0) return 0;
    if(DP[m][n] != -1)
    {
        return DP[m][n];
    }
    else
    {
        DP[m][n] = coin(m-1,n) + coin(m, n-arr[m-1]) ;
        return DP[m][n];
    }
}

int main()
{
    long long int n,m,cnt,i;
    for(i=0; i<21; i++)
    {
        arr[i] = (i+1)*(i+1)*(i+1);
        // printf("arr[i] = %lld\n",arr[i]);
    }
    memset(DP, -1, sizeof(DP));
    while(scanf("%lld",&n)==1)
    {
        m = 21;
        printf("%lld\n",coin(m,n));
    }
}
