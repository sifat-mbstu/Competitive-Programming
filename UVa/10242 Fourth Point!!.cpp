#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x1, x2, x3, x4, y1, y2, y3, y4, x, y;
    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4)==8)
    {
        if(x1 == x2 && y1 == y2){swap(x1, x3); swap(y1, y3);}
        if(x1 == x3 && y1 == y3){swap(x1, x2); swap(y1, y2);}
        if(x1 == x4 && y1 == y4){swap(x1, x3); swap(y1, y3);swap(x2, x4); swap(y2, y4);}
        if(x2 == x4 && y2 == y4){swap(x3, x4); swap(y3, y4);}
        if(x3 == x4 && y3 == y4){swap(x2, x4); swap(y2, y4);}

        x = x4 - x3 + x1;
        y = y4 - y3 + y1;
        printf("%.3lf %.3lf\n",x,y);
    }
}
