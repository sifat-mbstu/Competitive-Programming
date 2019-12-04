#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll fact(ll n)
{
    ll multi=1;
    for(ll i=2; i<=n; i++)
    {
        multi *= i;
    }
    return multi;
}
int main()
{
    ll ara[3000];
    ll i, j, n;
    ara[0] = 1;
    for(i=1;i<11;i++)
    {
        n = i - 1;
        ara[i] = (2*(2*n+1)*ara[i-1])/(n+2);
    }
    while(cin >> n)
    {
        cout << ara[n] << endl;
    }
}
