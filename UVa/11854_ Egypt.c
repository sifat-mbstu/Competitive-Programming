#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c,a_square,b_square,c_square,otivuj,num;
    while((scanf("%lf %lf %lf",&a,&b,&c)==3))
    {
        if(a==0 && b==0 && c==0)
        {
            break;
        }
        a_square = pow(a,2);
        b_square = pow(b,2);
        c_square = pow(c,2);
        num=a_square+b_square;
        if(c_square==num)
        {
            printf("right\n");
        }
        else
        {
            printf("wrong\n");
        }
    }
    return 0;
}
