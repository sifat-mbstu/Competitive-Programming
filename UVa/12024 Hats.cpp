#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Hats
{
    ll a;
    ll b;
}hat[20];
int main()
{
    ll i,j,k,TC;
    hat[0].a = 0;
    hat[1].a = 0;
    for(i=2;i<=12;i++)
    {
        hat[i].a = hat[i-1].a * i;
        if(i%2 != 0){ hat[i].a--;}
        else{hat[i].a++;}
        }
    hat[0].b = 1;
    for(i=1;i<=12;i++)
    {
        hat[i].b = hat[i-1].b * i;
    }
    cin >> TC;
    while(TC--)
    {
        cin >> i;
        printf("%lld/%lld\n",hat[i].a,hat[i].b);
    }
}
