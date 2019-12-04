#include<bits/stdc++.h>
using namespace std;
#define MAXX 1000010
#define ll long long
ll a[MAXX];
int main()
{
    ll i;
    //freopen("output.txt", "w" ,stdout);
    string s;
    while(cin >> s){
    if(s == "END") {break;}
    a[0] = s.size();
    for(i=1; ; i++)
    {
        a[i] = floor(log10(a[i-1]))+1;
        if(a[i] == a[i-1]){break;}
    }
    if(s=="1") i--;
    cout << i+1 <<endl;
    }
}
