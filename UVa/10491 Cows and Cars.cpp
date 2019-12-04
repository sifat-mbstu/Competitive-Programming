#include<bits/stdc++.h>
using namespace std;
int main()
{
    double cars, cows, shows, res;
    while(scanf("%lf %lf %lf",&cows, &cars, &shows)==3)
    {
        res = cars * (cows + cars - 1);
        res = res/((cars + cows)*(cars+cows - shows - 1));
        printf("%.5lf\n",res);
    }
}
