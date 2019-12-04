#include<bits/stdc++.h>
using namespace std;
#define FI freopen("input.txt", "r", stdin)
#define FO freopen("output.txt", "w", stdout)
#define ll long long
#define maxx  1005
long long fact[maxx];
void store_fact()
{
    int N,sum,i;
    for(N= 1; N < 1002; N++)
    {
        sum = 0;
        for(i = 1; i <= N/2; i++)
        {
            if(N% i== 0)
            {
                sum += i;
            }
        }
        sum += N;
        fact[N] = sum;
    }
}
int main()
{
  //  FI;FO;
    int TC,res,i,x=1;
    store_fact();
    int given;
    while(cin >> given)
    {
        if(given == 0) break;
        res = -1;
        for(i=1000; i >= 1; i--)
        {
            if(fact[i] == given)
            {
                res = i;
                break;
            }
        }
        printf("Case %d: %d\n",x++,res);
    }
}
