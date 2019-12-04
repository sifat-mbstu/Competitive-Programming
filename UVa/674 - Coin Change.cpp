#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll coin[] = {50, 25, 10, 5, 1};
ll DP[10][10000];
ll coin_change(ll pos, ll sum)
{
    if(sum<0)return 0;
    if(pos==5)
    {
        if(sum == 0)
        {
            return 1;
        }
        return 0;
    }
    if(DP[pos][sum]!=-1) return DP[pos][sum];
    ll val1 = coin_change(pos, sum-coin[pos]);
    ll val2 = coin_change(pos+1, sum);
    DP[pos][sum] = val1+val2;
    return val1+val2;
}

int main()
{
    ll val;
    memset(DP,-1,sizeof(DP));
    while(cin >> val)
    {

        cout << coin_change(0,val) << endl;
    }
}
