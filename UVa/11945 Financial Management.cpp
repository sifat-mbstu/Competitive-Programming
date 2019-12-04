#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    double earn,Sum , avg,r;
    int i,TC,j,c;
    scanf("%d",&TC);



    for(i=1;i<=TC;i++)
    {
        Sum = 0;
        for(j=0;j<12;j++)
        {
            scanf("%lf",&earn);
            Sum += earn;
        }
        avg = Sum/12.0;
        c = avg/1000.0;
        r = fmod(avg,1000.00);
        if(avg < 999.00) printf("%d $%.2lf\n",i,avg);
        else{ printf("%d $%d,%.2lf\n",i,c,r); }
    }
}
