#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    //freopen("ou.txt","w",stdout);
    int test;
    scanf("%d", &test);
    while(test--)
    {
        double r1,r2,r3;
        scanf("%lf %lf %lf", &r1, &r2, &r3);
        double a = r2 + r3;
        double b = r1 + r3;
        double c = r1 + r2;
        double s = (a + b + c)/2;
        double t_area = sqrt(s * ( s - a) * (s - b) * (s - c));
        double deg1 = acos((b * b + c * c - a *a) / (2.0 * b *c));
        double deg2 = acos((a * a + c * c - b * b) / (2.0 * a *c));
        double deg3 = acos((b * b + a * a - c *c) / (2.0 * a *b));
        double arc1 = r1 * r1 * 0.5 * deg1;
        double arc2 = r2 * r2 * 0.5 * deg2;
        double arc3 = r3 * r3 * 0.5 * deg3;
        double mid_area = t_area - (arc1 + arc2 + arc3);
        printf("%.6lf\n",mid_area);
    }
    return 0;
}
