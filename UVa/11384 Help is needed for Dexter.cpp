#include<bits/stdc++.h>
using namespace std;
#define FI freopen("input.txt", "r", stdin)
#define FO freopen("output.txt", "w", stdout)
#define ull unsigned long long
int main()
{
//    FI,FO;
    ull N, n;
    long long i;
    while(cin >> n){
    for(i = 0; i < 32; i++)
    {
        N = (double)pow(2, i) - 1.0;
        if( N >= n)
        {
            break;
        }
    }
    printf("%lld\n",i);
    }
}
