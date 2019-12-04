///Accepted
#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
int main()
{
    double a,b,c, p, in,rose, violet, sunflower, out, out_cir, tri;
    while(cin >> a >> b >> c){
    p = a + b + c;
    p /= 2.0;
    tri= sqrt(p*(p-a)*(p-b)*(p-c));

    in = tri/p;
    rose = pi * in * in;
    violet = tri - rose;
    out = a * b * c;
    out = out / (4.0 * tri);
    out_cir = pi * out * out;
    sunflower = out_cir - tri;
    printf("%.4lf %.4lf %.4lf\n", sunflower, violet, rose);
}
}
