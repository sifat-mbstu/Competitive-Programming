#include<bits/stdc++.h>
using namespace std;
int main()
{    int day = 0;
    double H,U,D,F,ini, af_cli, af_sli,cli,FF;
    while(scanf("%lf %lf %lf %lf",&H,&U,&D,&F)==4){
    day = 0;
    af_cli = 0.0;
    ini = 0.0;
    bool t = false;
    FF = F/100.0;
    while(af_cli < H)
    {
        if(af_sli <= 0.0){t = true;break;}
        day++;
        //FF = (F * U) /100.0;
        cli = U;
        af_cli = ini + cli;
        af_sli = af_cli - D;
        U -= (U * FF);
        ini = af_sli;
    }
    if(t) printf("Failed = %d\n", day);
    else printf("succeed = %d\n", day);
    }
}
