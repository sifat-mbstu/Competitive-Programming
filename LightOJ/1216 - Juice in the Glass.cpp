#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
int main()
{
    int TC,idx =0;
    scanf("%d",&TC);
    while(TC--)
    {
        double r1,r2,h,p;
        scanf("%lf %lf %lf %lf",&r1, &r2, &h, &p);
        double dr = r1-r2;
        double theta = atan(h/dr);

        double fh = r1 * tan(theta);
        double x = (fh-h+p)/tan(theta);

        double v1 = (pi*(x*x)*(fh-h+p))/3.0;
        double v2 = (pi*(r2*r2)*(fh-h))/3.0;
        double vol = v1-v2;
        printf("Case %d: %.10lf\n",++idx,vol);
    }
}
