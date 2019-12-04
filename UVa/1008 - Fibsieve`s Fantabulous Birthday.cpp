#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
int main()
{
    ull T,i,k,n,x,r,di,f,a,b;
    scanf("%llu",&T);
    for(k=1;k<=T;k++){
    scanf("%llu",&n);
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

    if((x-1) % 2 ==0)
    {
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
            }
            else if ( b > a)
            {
                a -= (n-r-1);
                break;
            }
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
            }
            else if ( a > b)
            {
                b -= (n-r-1);
                break;
            }
        }
    }
    printf("Case %llu: %llu %llu\n",k,a,b);
    }
}

