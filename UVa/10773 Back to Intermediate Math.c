#include<stdio.h>
#include<math.h>
int main()
{
    int i,N;
    double d,v,u,res;
    double res_1,res_2;
    scanf("%d",&N);
    for(i=1; i<=N; i++)
    {
        scanf("%lf%lf%lf",&d,&v,&u);
        if(v>=u || u==0 || v==0)
        {
            printf("Case %d: can't determine\n",i);
        }
        else
        {
            res_1 = d / u;

            //printf("%lf\n",res_1);
            res_2 = sqrt((u*u)-(v*v));

            //printf("%lf\n",res_1);
            res_2 = d / res_2;

            //printf("%lf\n",res_1);

            res = res_2 - res_1;
            printf("Case %d: %.3lf\n",i,res);
        }
    }
    return 0;
}
