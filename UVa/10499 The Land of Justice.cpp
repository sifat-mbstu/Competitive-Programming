#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    while(scanf("%lld",&n)==1)
    {
        if(n<0){break;}
        if(n==1){n = 0;}
        printf("%lld%%\n",n*25);
    }

}
