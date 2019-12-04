#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b,c,d,l,x;
    ll i,j, div_count,f_x;
    while(cin >> a >> b >> c >> d >> l){
    if(a==0 && b==0 && c==0 && d==0 && l==0)
    {
        break;
    }
    div_count = 0;
    for(x=0;x<=l;x++)
    {
        f_x = a*x*x + b*x + c;
        if(f_x % d == 0){div_count++;}
    }
    cout << div_count <<endl;
}
}
