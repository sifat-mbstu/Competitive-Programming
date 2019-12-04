#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,res;
    char c;
    while(cin >> a)
    {
    while (scanf("%c",&c))
    {
        if(c !=' '){break;}
    }
    cin >> b;
    if(c =='/'){ res = a/ b;}
    else{ res = a % b;}
    cout << res << endl;
    }
}
