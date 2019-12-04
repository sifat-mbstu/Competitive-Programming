#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1111111111111111111
#define ff first
#define ss second
#define pii pair<ll,ll>

#define piii pair<ll,pii>

piii fun(ll x1, ll y1, ll x2, ll y2)
{
    ll A = y1-y2;
    ll B = x1-x2;
    ll a = A;
    ll b = -B;
    ll c = (B*y1) - (A*x1);

    ll gcd = __gcd(a,b);
    gcd = __gcd(gcd,c);
    a = a/gcd;
    b = b/gcd;
    c = c/gcd;

    return piii(a,pii(b,c));
}
double dhal(ll x1, ll y1, ll x2, ll y2)
{
    double A = y1-y2;
    double B = x1-x2;
    if(B==0.0) return inf;
    double slope = A/B;
    return slope;
}
bool wtf(double a1, double b1, double c1, double a2, double b2, double c2)
{
    if(a1==a2 && b1==b2 && c1==c2)
    {
        return 1;
    }
    return 0;
}
int main()
{
    ll n;
    scanf("%lld",&n);
    printf("INTERSECTING LINES OUTPUT\n");
    while(n--){
    ll x1, x2, x3, x4;
    ll y1, y2, y3, y4;

    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);

    double m1 = dhal(x1,y1,x2,y2);
    double m2 = dhal(x3,y3,x4,y4);
    if(m1==m2)
    {
        piii now = fun(x1,y1,x2,y2);
        ll a1 = now.ff;
        ll b1 = now.ss.ff;
        ll c1 = now.ss.ss;

        now = fun(x3,y3,x4,y4);
        ll a2 = now.ff;
        ll b2 = now.ss.ff;
        ll c2 = now.ss.ss;
//        printf("a1 = %lld %lld %lld\n",a1,b1,c1);
//        printf("a2 = %lld %lld %lld\n",a2,b2,c2);

        if(wtf(a1,b1,c1,a2,b2,c2))
        {
            printf("LINE\n");
        }
        else printf("NONE\n");
    }
    else
    {
        piii now = fun(x1,y1,x2,y2);
        double a1 = now.ff;
        double b1 = now.ss.ff;
        double c1 = now.ss.ss;

        now = fun(x3,y3,x4,y4);
        double a2 = now.ff;
        double b2 = now.ss.ff;
        double c2 = now.ss.ss;

        double x = ((b1*c2) - (b2*c1)) / ((a1*b2) - (a2*b1));
        double y = ((c1*a2) - (c2*a1)) / ((a1*b2) - (a2*b1));
        printf("POINT %.2lf %.2lf\n",x,y);
    }
    }
    printf("END OF OUTPUT\n");
//    printf("%lld %lld %lld\n",a1,b1,c1);
}
