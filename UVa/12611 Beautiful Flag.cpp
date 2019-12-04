#include<bits/stdc++.h>
using namespace std;
int main()
{
    float rad,width,length,up_left_x,up_left_y,up_right_x,up_right_y,low_left_x,low_left_y,low_right_x,low_right_y;
    int i,test;
    scanf("%d",&test);
    for(i=1;i<=test;i++){
    scanf("%f",&rad);
    length = rad * 5;
    up_left_x = (0.45*length)*(-1);
    width = 0.60 * length;
    //printf("width=%f\n",width);
    up_left_y = width / 2.0;

    up_right_x= length + up_left_x;
    up_right_y= up_left_y;

    low_left_x=up_left_x;
    low_left_y=-up_left_y;

    low_right_x = up_right_x;
    low_right_y=-up_right_y;
    printf("Case %d:\n",i);
    printf("%.0f %.0f\n",up_left_x,up_left_y);
    printf("%.0f %.0f\n",up_right_x,up_right_y);
    printf("%.0f %.0f\n",low_right_x,low_right_y);
    printf("%.0f %.0f\n",low_left_x,low_left_y);
    }
    return 0;
}
