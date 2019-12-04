#include<stdio.h>
#include<stdlib.h>
int main()
{
    int ini,Total_Rot,F1,S2,T3,Ang,A1,A2,A3;
    while((scanf("%d %d %d %d",&ini,&F1,&S2,&T3))==4)
    {

        if(ini==0 && F1==0 && S2==0 && T3==0)
        {
            exit(0);
        }
        Total_Rot=0;
        if(F1>ini)
        {
            A1=40-(F1-ini);
        }
        else
        {
            A1=ini - F1;
        }

        if(F1>S2)
        {
            A2=40-(F1-S2);
        }
        else
        {
            A2=S2-F1;
        }

        if(T3>S2)
        {
            A3=40-(T3-S2);
        }
        else
        {
            A3=S2-T3;
        }

        Ang = A1 + A2 + A3;
        Total_Rot = Ang*9 + 1080;
        printf("%d\n",Total_Rot);
    }
    return 0;
}
