#include<bits/stdc++.h>
using namespace std;
int main()
{
    double s,u,v,w,res;
    while(scanf("%lf %lf %lf",&u,&v,&w)==3)
    {
        s = u + v + w;
        s = s/2;
        s = s * (s-u) * (s-v) * (s-w);
        if(s <= 0 )
        {
            res = -1;
        }
        else
        {
            s = sqrt(s);
            res = (4 * s) / 3;
        }
        printf("%.3lf\n",res);
    }
}
