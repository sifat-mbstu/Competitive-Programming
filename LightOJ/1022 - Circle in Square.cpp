#include<bits/stdc++.h>
using namespace std;
#define pi 2*acos(0.0)
int main()
{
    int TC, ind=0;
    cin >> TC;
    while(TC--)
    {
        double r;
        scanf("%lf",&r);
        double sq_area = 4*r*r;
        double cir_area = pi * r*r;
        double res = sq_area - cir_area;
        printf("Case %d: %.2lf\n",++ind,res);
    }
}
