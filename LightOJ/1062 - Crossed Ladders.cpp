#include<bits/stdc++.h>
using namespace std;

#define inf INT_MAX/3
#define pi acos(-1.0)

#define pii pair<int,int>
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
double x, y, c;
double cal(double w)
{
    double m = (x*x)-(w*w);
    m = sqrt(m);

    double n = (y*y)-(w*w);
    n = sqrt(n);
    return (m*n)/(m+n);
}

double binary(double b, double e)
{
    double mid;
    double ans;
    int cnt = 100;
    while(b<=e)
    {
        if(!cnt--)break;
        mid = (b+e)/2;
        double res = cal(mid);
//        printf("res = %lf\n",res);
//        getchar();
        if(res <= c)
        {
            ans = mid;
            e = mid;
        }
        else
        {
            b = mid;
        }
    }
    return ans;
}

int main()
{
    int TC;
    int ind = 0;
    cin >> TC;
    while(TC--){
    scanf("%lf %lf %lf",&x, &y, &c);
    double ans = binary(0, min(x,y)) ;
    printf("Case %d: %.10lf\n",++ind,ans);
    }
}
