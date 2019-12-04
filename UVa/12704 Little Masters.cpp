#include<bits/stdc++.h>
using namespace std;

int main()
{
    double x,y,r,sq;
    int test;
    scanf("%d",&test);
    while(test--)
    {
    scanf("%lf %lf %lf", &x, &y, &r);
    sq = x*x + y*y;
    //printf("\nsq==%d\n\n",sq);
    sq = sqrt(sq);
    //printf("\nsq==%d\n\n",sq);
    printf("%.2lf %.2lf\n",r-sq,sq+r);
    }
    return 0;
}
