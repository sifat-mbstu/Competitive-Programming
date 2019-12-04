#include<stdio.h>
#include<math.h>
int main()
{
    int n,Case=1;
    double u,v,a,s,t,p;
    do
    {
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            scanf("%lf%lf%lf",&u,&v,&t);
            s=((u+v)/2)*t;
            a=(v-u)/t;
            printf("Case %d: %.3lf %.3lf\n",Case,s,a);
            break;
        case 2:
            scanf("%lf%lf%lf",&u,&v,&a);
            t=(v-u)/a;
            s=((u+v)/2)*t;
            printf("Case %d: %.3lf %.3lf\n",Case,s,t);
            break;
        case 3:
            scanf("%lf%lf%lf",&u,&a,&s);
            p=pow(u,2)+2*a*s;
            v=sqrt(p);
            t=(v-u)/a;
            printf("Case %d: %.3lf %.3lf\n",Case,v,t);
            break;
        case 4:
            scanf("%lf%lf%lf",&v,&a,&s);
            p=pow(v,2)-2*a*s;
            u=sqrt(p);
            t=(v-u)/a;
            printf("Case %d: %.3lf %.3lf\n",Case,u,t);
        }
        Case++;
    }
    while(n!=0);
    return 0;
}
