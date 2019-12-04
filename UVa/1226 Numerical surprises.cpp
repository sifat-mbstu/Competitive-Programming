#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, num,rem, i, TC;
    string s;
    cin >> TC;
    while(TC--){
    cin >> n >> s;
    rem = 0;
    int len = s.size();
    for(i=0; i<len; i++)
    {
        int a = s[i] - '0';
        num = rem*10 + a;
        rem = num %  n;
    }
    cout << rem << endl;
    }
}
