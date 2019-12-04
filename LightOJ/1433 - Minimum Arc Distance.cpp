#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
double getdis(double x1, double y1, double x2, double y2)
{
    double dis = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
    dis = sqrt(dis);
    return dis;
}
int main()
{
        int TC, idx = 0;
        scanf("%d",&TC);
        while(TC--){
        double ox, oy, ax, ay, bx, by;
        scanf("%lf %lf %lf %lf %lf %lf", &ox, &oy, &ax, &ay, &bx, &by);
        double oa,ob,ab;
        oa = getdis(ox,oy,ax,ay);
        ob = getdis(ox,oy,bx,by);
        ab = getdis(ax,ay,bx,by);

        double theta = ((oa*oa + ob*ob) - (ab*ab))/(2.0*oa*ob);
        theta = acos(theta);
        theta = (180.0*theta)/ pi;
        double res = (2.0*pi*oa*theta)/360.0;
        printf("Case %d: %lf\n",++idx,res);
        }
}
