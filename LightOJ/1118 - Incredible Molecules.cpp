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
    int tc,idx=0;
    scanf("%d",&tc);
    while(tc--)
    {
        double r1, x1,y1,r2,x2,y2;
        scanf(" %lf %lf %lf %lf %lf %lf",&x1, &y1, &r1, &x2, &y2, &r2);

        double d = getdis(x1,y1,x2,y2);
        if(d>=(r1+r2)) {double a = 0.0;printf("Case %d: %.10lf\n",++idx,a); continue;}
        else if(r1>=(r2+d))
        {
            double res=pi*r2*r2;
            printf("Case %d: %.10lf\n",++idx,res);
            continue;
        }
        else if(r2>=(r1+d))
        {
            double res=pi*r1*r1;
            printf("Case %d: %.10lf\n",++idx,res);
            continue;
        }
        double th1 =  acos( (((r1*r1) + (d*d)) - (r2*r2)) / (2.0* r1*d));
        double th2 =  acos( (((r2*r2) + (d*d)) - (r1*r1)) / (2.0* r2*d));
        double t1 = th1*2.0;
        double t2 = th2*2.0;
        th1 = (180.0 * th1)/pi;
        th2 = (180.0 * th2)/pi;
        th1 = 2.0 * th1;
        th2 = 2.0 * th2;

        double a1 = ((r1*r1)*(t1-sin(t1)))/2.0;
        double a2 = ((r2*r2)*(t2-sin(t2)))/2.0;

        double a = a1+a2;
        printf("Case %d: %.10lf\n",++idx,a);
    }
}
