#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll F (ll N, ll P, ll M)
{
    if(P==0) return 1;
    if(P%2==0)
    {
        ll ret = F(N, P/2,M);
        return ((ret%M)*(ret %M)) % M;
    }
    else
    {
        return ((N%M)*(F(N,P-1,M) %M))%M;
    }
}
int main()
{
    ll N,M,P;
    char c ;
    while(cin >> N >> P >> M)
    {
        cout << F(N,P,M) <<endl;
    }
}
