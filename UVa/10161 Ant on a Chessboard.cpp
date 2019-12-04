#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
int main()
{
    ull i,n,x,r,di,f,a,b;

    while(scanf("%llu",&n)==1){
            if(!n) {break;}
    x = ceil (sqrt(n));
    r = (x-1) * (x-1);
    f = x * x;
    di = (f - r) / 2;
    if((x-1) % 2 ==0)
    {
        a = x ;
        b = 1;
    }
    else
    {
        b = x ;
        a = 1;
    }
   //printf("x == %llu di== %llu\n",x,di);

    if((x-1) % 2 ==0)
    {
        //printf("YES\n");
        for(i=r; i<=f; i++)
        {

            if(a > b)
            {
                if((di+1) > (n-r))
                {
                    b+= (n-r-1);
                    break;
                }
                if((di+1) == (n-r))
                {

                    b = a;
                    break;
                }
                if((di+1) < (n-r))
                {
                    b+= di;
                    i+=di;
                    r += di;
                }
            }
            else if (a == b )
            {
                a--;
                r++;
                //printf("a = %llu b = %llu\n",a,b);
            }
            else if ( b > a)
            {
                a -= (n-r-1);
                break;
            }
           // printf("a = %llu b =%llu\n",a,b);
        }
    }

    if((x-1) % 2 !=0)
    {
        //printf("YES\n");
        for(i=r; i<=f; i++)
        {
            if(b > a)
            {
                if((di+1) > (n-r))
                {
                    a += (n-r-1);
                    break;
                }
                if((di+1) == (n-r))
                {
                    a = b;
                    break;
                }
                if((di+1) < (n-r))
                {
                    a+= di;
                    i+=di;
                    r += di;
                }
            }
            else if (a == b )
            {
                b--;
                r++;
                //printf("a = %llu b = %llu\n",a,b);
            }
            else if ( a > b)
            {
                b -= (n-r-1);
                break;
            }
           // printf("a = %llu b =%llu\n",a,b);
        }
    }
    printf("%llu %llu\n",a,b);
    }

}
//

