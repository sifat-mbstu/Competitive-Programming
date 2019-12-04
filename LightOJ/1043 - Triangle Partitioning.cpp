#include<bits/stdc++.h>
using namespace std;

double AB, BC, AC;
double Area_trivuj(double a, double b, double c)
{
    double s = (a+b+c)/2;
    s = s * (s-a) * (s-b) * (s-c);
    return sqrt(s);
}

double trivuj(double AD)
{
    double Ratio = AD/AB;
    return Area_trivuj(AD, BC*Ratio, AC*Ratio);
}
double binary(double BEG, double END, double ADE)
{
    double MID;
    int ind =0;
    while(BEG < END)
    {
        ind++;
        if(ind > 10000){break;}
        MID = (BEG+END)/2.0;
        double Area = trivuj(MID);
        if(Area == ADE) {return MID;}
        else if(Area > ADE){END = MID;}
        else{BEG = MID;}
        //printf("Mid = %lf\n",MID);
        //getchar();
    }
    return MID;
}
int main()
{
    int tc=0, TC;
    cin >> TC;
    while(TC--){
    double ABC, ADE, a;
    scanf("%lf %lf %lf %lf", &AB, &BC, &AC, &a);
    ABC = Area_trivuj(AB, BC, AC);
    ADE = ABC * (a / (a+1.0));
    double res = binary(0.0, AB, ADE );
    printf("Case %d: %lf\n",++tc,res);
    }
}
