#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll TC, ind = 0;
    bool yes;
    cin >> TC;
    while(TC--)
    {
        ll a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a,a+3);
        ll  A= a[0] * a[0];
        ll B = a[1] * a[1];
        ll C = a[2] * a[2];
        if(C == (A+B)) {printf("Case %lld: yes\n",++ind);}
        else {printf("Case %lld: no\n",++ind);}
    }
}
