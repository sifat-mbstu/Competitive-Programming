///Iterative form of Trailing Zeros
///Time Limit
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll i,n1, n2, five, div,sum;
    cin >> n1 >> n2;
    sum = 0;
    ll a = 0, b;
    for(i=n1; i<=n2; i++)
    {
        b = a;
        five = 5;
        a = 0;
        div = floor(i/five);
        while(div != 0)
        {
            a+=div;
            five *= 5;
            div = floor(i/five);
        }
       // cout << a << endl;
        if(a!=b) sum++;
    }
    cout << sum+1 << endl;
}
