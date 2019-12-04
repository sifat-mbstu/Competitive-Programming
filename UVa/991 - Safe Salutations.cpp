#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[20];
    int i, j, n;
    ara[0] = 1;
    for(i=1;i<11;i++)
    {
        n = i -1;
        ara[i] = (2*(2*n+1)*ara[i-1])/(n+2);
    }
    j = 0;
    while(cin >> n)
    {
        if(j) cout << endl;
        cout << ara[n] << endl;
        j = 1;
    }
}
