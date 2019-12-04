///Accepted
#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX/3
#define pi acos(-1.0)
double a, b;
double cal(double len)
{
//    printf("mid = %lf\n", len);
    double wid = (len * b)/a;
    double rad = (len * len) + (wid * wid);
    rad = sqrt(rad);
    rad /= 2.0;
    double angle = ((2*rad * rad) - (wid * wid)) / (2*rad * rad);
    angle = acos(angle) * (180.0/pi);
    double chap = (pi * rad * angle)/180.0;
    double tot = chap + chap + len + len;
    return tot;
}

double binary (double b, double e)
{
    int cnt = 50;
    double ans;
    while(b<e)
    {
        if(!cnt--){break;}
        double mid = (b+e)/2;
        double peri = cal(mid);
//       cout << peri << endl << endl;

        if(peri <= 400.0)
        {
            ans = mid;
            b = mid;
        }
        else
        {
            e = mid;
        }
    }
    return ans;
}

int main()
{
    int TC, ind = 0;
    cin >> TC;
    while(TC--){
    scanf("%lf : %lf",&a,&b);

//    printf("\n\n%lf %lf\n\n",a,b);
//    getchar();
    double len = binary(0.0,400.0);
    printf("Case %d: %.10lf %.10lf\n",++ind,len,(len*b)/a);
}
}
