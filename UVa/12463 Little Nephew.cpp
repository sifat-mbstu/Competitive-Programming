#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c,d,e,res;
    while(1){
    cin >> a >> b >> c >> d >> e;
    res = a * b * c * d * e * d * e;
    if ( res == 0) {break;}
    cout << res << endl;
    }
}
