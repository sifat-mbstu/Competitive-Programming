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
            bool alice = 1;
            if(n == 0){break;}
    for(i = 0; i <= 31; i++)
    {
        N = (double)pow(2, i) - 1.0;
        if( N == n)
        {
            alice = 0;
        }
    else if (N > n)
    {
        break;
    }
    }
    if(alice) printf("Alice\n",i);
    else printf("Bob\n");
    }
}
