#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FI freopen("input.txt", "r", stdin)
#define FO freopen("output.txt", "w", stdout)
bool prime(int n)
{
    int i;
    for(i=2; i <= n/2; i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}
int main()
{
    //FO;
    ll n, res, res1, res2;
    bool pri;
    while(cin >> n)
    {
        if(!n) break;
        res = 0;
        pri = prime(n);
        if(pri)
        {
            res1 = round(pow((double)2.0, (double) n-1.0));
            res2 = round(pow((double)2.0, (double) n)) - 1;
            res = res1 * res2;
        }
        if(n==11 || n==23 || n==29){res = 0;}
        if(!pri){printf("Given number is NOT prime! NO perfect number is available.\n");}
        else if(pri && !res){printf("Given number is prime. But, NO perfect number is available.\n");}
        else {printf("Perfect: %lld!\n",res);}
    }
}
