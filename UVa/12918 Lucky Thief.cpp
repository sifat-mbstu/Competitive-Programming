#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll m,n,TC,res;
    scanf("%lld",&TC);
    while(TC--)
    {
        scanf("%lld %lld",&n,&m);
        res = (m-n)*n;
        res += ((n+1)*n)/2;
        res -= n;
        printf("%lld\n", res);
    }
}
