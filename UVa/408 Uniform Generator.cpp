#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll GCD (ll a, ll b)
{
    while(b!=0)
    {
        a = a % b;
        swap(a,b);
    }
    return a;
}
int main()
{
    ll a,b,gcd;
    while(scanf("%lld %lld",&a, &b)==2){
    gcd = GCD(a,b);
    if(gcd==1)
    {
        printf("%10lld%10lld    Good Choice\n\n",a,b);
    }
    else{
        printf("%10lld%10lld    Bad Choice\n\n",a,b);
    }
    }
}
