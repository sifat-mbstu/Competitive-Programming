#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX/3
double X[100], Xr;
double Y[100], Yr;

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double Binary_search(double x1,double y1,double x2,double y2)
{
    double C, a, b;
    int z = 200;
    while(z--)
    {
        double mid_x = (x1 + x2) / 2;
        double mid_y = (y1 + y2) / 2;
        //printf("mid_x = %d mid_y = %d\n",mid_x, mid_y);
        C = distance(x1,y1,Xr,Yr) ;
        a = distance(mid_x,mid_y,Xr,Yr);
        b = distance(mid_x,mid_y,x1,y1);
        if((C*C) < ((a*a) + (b*b)))
        {
            x2 = mid_x;
            y2 = mid_y;
        }
        else if((C*C) > ((a*a) + (b*b)))
        {
            x1 = mid_x;
            y1 = mid_y;
        }
        else{
            return a;
        }
    }
     return a;
}

int main()
{
    int i,n;
    double Min = inf;
    //cout << Min;
    while(cin >> n >> Xr >> Yr){
    Min = inf;
    for( i=0; i<n; i++)
    {
        cin >> X[i] >> Y[i];
    }
    X[i] = X[0];
    Y[i] = Y[0];
    for( i=0; i<n; i++)
    {
        double Rad = Binary_search(X[i], Y[i], X[i+1], Y[i+1]);
        Min = min(Rad, Min);
    }
    printf("%.3lf\n",Min);
    }
}
