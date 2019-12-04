#include<bits/stdc++.h>
#define pi 2*acos(0.0)
using namespace std;
int main()
{
    double length , width, whole_area,rad,Area_red,Area_green;
    int Test,i;
    scanf("%d",&Test);
    while(Test--){
    scanf("%lf",&length);
    width = length * 0.6;
    whole_area = width *length;
    //printf("whole_area = %f\n",whole_area);
    rad = length / 5;
    Area_red = pi * rad * rad;
    Area_green = whole_area - Area_red;
    printf("%.2lf %.2lf\n",Area_red,Area_green);
    }
    return 0;
}
