#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main()
{
    ll a, b, c, n, x, sum;
    while(cin >> n){
    a = 0, b = 1, c = 2;
    x = 4;
    while(x<=n)
    {
        sum = a + b + c;
        a = b;
        b = c;
        c = sum;
        x++;
    }
    if(n==0){sum = 0;}
    else if(n==1){sum = a;}
    else if(n==2){sum = a+b;}
    else if(n==3){sum = a+b+c;}
    cout << sum << endl;
    }
}
