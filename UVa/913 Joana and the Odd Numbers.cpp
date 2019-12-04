#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
int main()
{
    ull N,res,Num,line;
    while(scanf("%llu",&N)==1)
    {
        line = (N+1)/2;
        Num = line * line;
        Num = (Num * 2) - 1;
        res = Num + (Num-2) + (Num - 4);
        cout << res << endl;
    }
    return 0;
}
