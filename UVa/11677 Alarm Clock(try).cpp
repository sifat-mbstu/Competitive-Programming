///accepted
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,res1,Fin_res,res2,res;
    while(scanf("%d %d %d %d",&a,&b,&c,&d)==4){
            if(a==0 && b==0 && c==0 && d==0){break;}
    res1 = a*60 + b;
    res2 = c*60 + d;
    res = res1 - res2;
    if(res>0 && c>12){c+=24; res2=c*60+d; res=res1 - res2;}
    if(res<0){Fin_res = abs(res); }
    else if(res>0){Fin_res = 1440 - res ;}
    else if(res==0){Fin_res = 0;}

    printf("%d\n", Fin_res);
    }
}
