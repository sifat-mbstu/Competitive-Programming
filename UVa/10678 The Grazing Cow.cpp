#include<bits/stdc++.h>
#define pi 2*acos(0.0)
using namespace std;
int main()
{
    double d,l,a,b;
    int TC,i,j;
    cin >> TC;
    while(TC--)
    {
        cin >> d >> l;
        a = sqrt(((l/2)* (l/2)) - ((d/2)* (d/2)));
        b = l/2;
        printf("%.3lf\n",pi*a*b);
    }
}
