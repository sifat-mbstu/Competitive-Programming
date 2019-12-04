#include<stdio.h>
int main()
{
    double height, climb , slide, fatigue, Dis_cli, he_af_cli, ini_he, he_af_sl,fati_fac;
    while(scanf("%lf %lf %lf %lf", &height ,&climb,&slide,&fatigue)==4){
    fati_fac=(fatigue/100.0)*climb;
    Dis_cli=climb;
    while(he_af_cli>0.0 && he_af_cli<height)
    {
        ini_he=he_af_sl;
        he_af_cli=ini_he+Dis_cli;
        he_af_sl=he_af_cli - slide;
        Dis_cli = Dis_cli - fati_fac;
    }
    if(he_af_cli <=0){printf("failed"); }
    else{printf("succeed");}
    }
}
