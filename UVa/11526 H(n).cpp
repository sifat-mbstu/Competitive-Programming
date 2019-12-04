#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,half,j,a,i,TC,res;
    scanf("%lld", &TC);
    while(TC--)
    {
        scanf("%lld", &n);
       // half = n/2;
        res = 0;
        j = 1;
        for(i=1; i<=n; i++)
        {
            a = n/i;
            i = n/a;
            res += (i-j)*a;
            j = i;
        }
        res = res + n ;
        printf("%lld\n", res);
    }
    return 0;
}
