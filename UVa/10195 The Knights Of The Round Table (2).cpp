#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a, b, c, s, area, r, tri;
    while(cin >> a >> b >> c)
    {
        if(a<= 0.0 || b <=0.0 || c <= 0.0)
        {
            r=0.0;
        }
        else
        {
            s = (a+b+c)/2.0;
            r = sqrt(s*(s-a)*(s-b)*(s-c));
            r = r/s;
        }
        printf("The radius of the round table is: %.3lf\n",r);
    }
}
