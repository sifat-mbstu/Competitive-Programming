#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, TC;
    cin >> TC;
    while(TC--){
    double sum = 0.0;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        sum += log10(i);
    }
    int res = floor(sum) + 1;
    cout  << res << endl;
    }
}
