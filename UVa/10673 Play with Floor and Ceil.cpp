#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b,x,k,p,q,TC;
    cin >> TC;
    while(TC--){
    scanf("%lld %lld",&x,&k);
    a = floor((double)x/k);
    b = ceil((double)x/k);
    for(ll i=0; i<= x; i++)
    {
        //    cout << a << b << endl;
        if((x-i*a)%b == 0)
        {
            p = i;
            q = (x-i*a)/b;
         //   cout  << p << endl;
            break;
        }
    }
    cout << p << " " << q << endl;
    }
}
