#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
double fndangle (double oa, double ob, double ab)
{
        double theta = ((oa*oa + ob*ob) - (ab*ab))/(2.0*oa*ob);
        theta = acos(theta);
        theta = (180.0*theta)/ pi;
        return theta;
}

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
    double r1,r2,r3;
    scanf("%lf %lf %lf",&r1, &r2, &r3);

    double a = r1+r3;
    double b = r2+r3;
    double c = r1+r2;

    double trivuj_area = fnd_area(a,b,c);

    double A = fndangle(b,c,a);
    double B = fndangle(c,a,b);
    double C = fndangle(a,b,c);

    double r2_area = (pi*(r2*r2))*( A /360.0);
    double r1_area = (pi*(r1*r1))*( B /360.0);
    double r3_area = (pi*(r3*r3))*( C /360.0);

    double tot = r1_area + r2_area + r3_area;
    double res= trivuj_area - tot;
    printf("Case %d: %.10lf\n",++idx,res);
    }
}
