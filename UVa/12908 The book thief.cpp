#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll sum,n,i,tot_page,missing_page;
    while(scanf("%lld",&sum)){
            if(sum==0){break;}
    int q = sqrt(sum);
    n = 0;
    for(i=q;n<sum ;i++)
    {
        n = i*(i+1) * 0.5 ;
    }
    if(n == sum)
    {
        tot_page = i;
        missing_page = i;
    }
    else if(n > sum )
    {
        tot_page = i-1;
        missing_page = n - sum;
    }
    printf("%lld %lld\n",missing_page , tot_page);
    }
}
