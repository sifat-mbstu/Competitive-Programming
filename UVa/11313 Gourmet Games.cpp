#include<bits/stdc++.h>
using namespace std;

#define FI freopen("input.txt", "r", stdin)
#define FO freopen("output.txt", "w", stdout)
int main()
{
    int TC, n,m,div,rem,t;
    cin >> TC;
    while(TC--){
            t = 0;
    cin >> n >> m;
    while(n >= m){
    rem = n % m;
    n = n / m;
    t += n;
    n += rem;
    }
    if(n==1){ cout << t << endl;}
    else cout << "cannot do this" << endl;
}
}

