#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b,c,n;
    while(scanf("%lld %lld %lld", &a,&b,&c)==3)
    {
        if(!a && !b && !c) break;
        a -= 7;
        b -= 7;
        n = a * b;
        if(n%2 ==0) printf("%lld\n",n/2);
        else printf("%lld\n",(n/2) + c);
    }
}
