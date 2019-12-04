#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fib( ll n)
{
    if(n<=1)
    {
        return n;
    }
    ll F1,F2,F,i;
    F1=0,F2=1;
    for(i=2; i<=n; i++)
    {
        F = F1 + F2;
        F1 = F2;
        F2 = F;
    }
    return F;
}
int main()
{
    ll n;
    while(cin >> n)
    {
        if(n==-1) break;
        cout << fib(n+2) - 1 << " " << fib(n+3) - 1 << endl;
    }
}
