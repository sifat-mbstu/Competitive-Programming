#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
double fnd_area(double a, double b, double c)
{
    double s = (a+b+c)/2.0;
    double area  = s * (s-a) * (s-b) * (s-c);
    return sqrt(area);
}
int main()
{
    int TC,idx=0;
    scanf("%d",&TC);
    while(TC--){
    double a,b,c,d;
    scanf("%lf %lf %lf %lf",&a, &b, &c, &d);
    double ex = abs(a-c);
    double area = fnd_area(d,b,ex);
    double h = (2.0*area)/ex;
    double trap = ((a+c)*h)/ 2.0;
    printf("Case %d: %.10lf\n",++idx,trap);
    }
}
