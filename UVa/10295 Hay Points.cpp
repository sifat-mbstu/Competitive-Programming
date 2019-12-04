#include<bits/stdc++.h>
using namespace std;
#define FI freopen ("input.txt", "r", stdin);
#define FO freopen ("output.txt", "w", stdout);
#define ll long long
int main()
{
    //FI;FO;
    string s;
    map <string , ll> mymap;
    ll n, m, num,i,sum;
    cin >> n >> m;
    for(i = 0; i < n; i++)
    {
        cin >> s >> num;
        mymap[s] = num;
    }
    for(i = 0; i< m; i++)
    {
        sum = 0;
        while(cin >> s)
        {
            if(s[0] == '.') break;
            if(mymap[s] > 0){ sum += mymap[s];}
        }
        cout << sum << endl;
    }
}
