#include<bits/stdc++.h>
using namespace std;
int main()
{
    int TC, ind = 0;
    cin >> TC;
    while(TC--)
    {
        int x1, x2, y1, y2, a, b;
        bool t1,t2;
        cin >> x1 >> y1 >> x2 >> y2;
        int M;
        if(x1 > x2) swap(x1,x2);
        if(y1 > y2) swap(y1,y2);
        cin >> M;
        printf("Case %d:\n",++ind);
        while(M--)
        {
            cin >> a >> b;

            if((a <= x2 && a>= x1) && (b<=y2 && b>= y1)) printf("Yes\n");
            else printf("No\n");
        }
    }
}
