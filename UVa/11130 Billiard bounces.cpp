#include<bits/stdc++.h>
using namespace std;
const double conv = 3.14159265 / 180;
int main()
{
    int a, b, v, Angle, Time;
    while(cin >> a >> b >> v >> Angle >> Time){
    if(!a && !b && !v && !Angle && !Time){break;}
    ///Let's Count Horizontal Bounces
    int Hori_bounce =  (v * Time) * sin(Angle * conv);
    Hori_bounce += b;
    Hori_bounce = Hori_bounce/(2*b);

    ///Let's Count Vertical Bounces
    int Ver_bounce = (v * Time) * cos(Angle * conv);
    Ver_bounce += a;
    Ver_bounce = Ver_bounce/(2*a);

    printf("%d %d\n", Ver_bounce, Hori_bounce);
    }
}
