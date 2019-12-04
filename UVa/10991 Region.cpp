#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
int main()
{
    int TC;
    double r1,r2,r3,area_region;
    double s,mid,area_trngle, ang1,ang2,ang3,area_arc;
    double a,b,c,arc1,arc2,arc3;
    cin >> TC;
    while(TC--){
    scanf("%lf %lf %lf",&r1,&r2,&r3);
    a = r2 + r3;
    b = r1 + r3;
    c = r1 + r2;

    s = (a + b + c) / 2.0;
    area_trngle = s * (s-a) * (s-b) * (s-c);
    area_trngle = sqrt(area_trngle);

    ang1 = acos((b*b + c*c - a*a) / (2.0*b*c));
    ang2 = acos((a*a + c*c - b*b) / (2.0*a*c));
    ang3 = acos((b*b + a*a - c*c) / (2.0*a*b));

    arc1 = r1*r1 * 0.5 * ang1;
    arc2 = r2*r2 * 0.5 * ang2;
    arc3 = r3*r3 * 0.5 * ang3;

    area_arc = arc1+arc2+arc3;
    area_region = area_trngle - area_arc;
    printf("%.6lf\n",area_region);
}
}
