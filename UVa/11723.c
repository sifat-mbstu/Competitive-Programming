#include<stdio.h>
int main()
{
    int R,l,T,count,case1=0;
    while(scanf("%d %d",&R,&T)==2)
    {
        if(R==0 && T==0){break;}
        l=T;
        count=0;
        case1++;
        while(T<R)
        {
            T=T+l;
            count++;
            if(count>26)
            {
                break;
            }
        }
        if(count>26)
        {
            printf("Case %d: impossible\n",case1);
        }
        else
        {
            printf("Case %d: %d\n",case1,count) ;
        }
    }
    return 0;
}
