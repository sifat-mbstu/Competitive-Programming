#include<bits/stdc++.h>
using namespace std;

#define FI freopen("input.txt", "r", stdin)
#define FO freopen("output.txt", "w", stdout)
int main()
{
    int TC, n,m,div,rem;
    cin >> TC;
    while(TC--)
    {
        cin >> n >> m;

        if(((n-1) % (m-1)) == 0)
        {
            cout << (n-1) / (m-1) << endl;
        }
        else cout << "cannot do this" << endl;
    }
}


