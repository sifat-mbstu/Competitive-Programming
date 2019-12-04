#include <bits/stdc++.h>
#define pi acos(-1.0)
#define N 1000000
using namespace std;
int ans [500000 + 5];
int main ()
{
    ans [1] = 1;
    ans [2] = 2;
    int t = 2;
    for ( int i = 3; i <= 500000; i++ )
    {
        if ( i < t ) t = 2;
        ans [i] = t;
        t += 2;
    }
    int n;
    while ( scanf ("%d", &n) && n )
    {
        printf ("%d\n", ans [n]);
    }
    return 0;
}
