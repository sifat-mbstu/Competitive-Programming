#include <bits/stdc++.h>
using namespace std;
int main()
{

    int x1, x2, y1, y2, dif_x, dif_y,res;

        while(scanf("%d %d %d %d",&x1, &y1, &x2, &y2)==4)
    {
        if(!x1 && !x2 && !y1 && !y2) break;

        dif_x = abs(x1 - x2);
        dif_y = abs(y1 - y2);

        if(x1==x2 && y1==y2)
        {
            res = 0;
        }
        else if(x1==x2)
        {
            res =1;
        }
        else if(y1==y2)
        {
            res =1;
        }
        else if(dif_x == dif_y)
        {
            res = 1;
        }
        else
        {
            res = 2;
        }
        printf("%d\n",res);
    }
    return 0;
}
