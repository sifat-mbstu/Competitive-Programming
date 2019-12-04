#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,a,b,i,ans,d;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d",&a,&b);
        if(a == 2 || b == 2)
        {
            if(b==2){ swap (a,b);}
            if(b%4==0){ans = b;}
            else if (b%4 == 2 ||  b%4 == 3)
            {
                d = b / 4;
                ans = (d+1) * 4;
            }
            else if ( b%4 == 1)
            {
                d = b / 4;
                ans = ((d+1) * 4) - 2;
            }
        }
        else if(a == 1 || b == 1)
        {
            if(a==1){ ans = b;}
            else { ans = a;}
        }
        else
        {
            d = a * b;
            if(d % 2 ==0){ans = d / 2;}
            else if(d % 2 !=0){ans = d / 2 + 1;}
        }
        printf("Case %d: %d\n",i,ans);
    }
}
