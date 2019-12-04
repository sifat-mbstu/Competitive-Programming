#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main()
{
    ll ara[25], res, n, i;
    ara[0] = 1;
    for(i=1; i<=24; i++)
    {
        res = (2 * ((2*i) + 1) * ara[i-1]) / (i+2);
        //cout << res << endl;
        //res *= ara[i-1];

        ara[i] = res;
    }
    while(scanf("%llu",&n) == 1)
    {
        for(i=0; i<=20; i++)
        {
            //cout << "ara[" << i << "] = " << ara[i] << endl;
            if(n>= ara[i] && n < ara[i+1])
            {
                cout << i+1 << endl;
                break;
            }
        }
    }
}
