#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000000];
ll int LCM( ll a, ll b)
{
    ll u = a, v = b,rem;
    while(b!=0)
    {
        rem = a%b;
        a = b;
        b = rem;
    }
    return (u*v)/a;
}
ll GCD( ll a, ll b)
{
    ll u = a, v = b,rem;
    while(b!=0)
    {
        rem = a%b;
        a = b;
        b = rem;
    }
    return a;
}
int main()
{
    ll k,n,lcm,i,sum,gcd,TC;
    scanf("%lld",&TC);
    for(k = 1; k <= TC; k++)
    {
        scanf("%lld",&n);
        sum = 0;
        for(i=0; i<n; i++)
        {
            scanf("%lld",&a[i]);
            if(i==1) lcm = LCM(a[0],a[1]);
            else if(i > 1) lcm = LCM(lcm,a[i]);
        }
        if(n==1)
        {
            printf("Case %lld: %lld/%lld\n",k,a[0],1);
        }
        else
        {
            for(i=0; i<n; i++)
            {
                sum += lcm / a[i];
            }
            n *= lcm;
            gcd=GCD(n, sum);
            printf("Case %lld: %lld/%lld\n",k,n/gcd,sum/gcd);
        }
    }
}
