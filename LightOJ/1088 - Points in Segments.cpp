#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define all(ar) ar.begin(), ar.end()
int n;
vi point;
 
int main()
{
    int TC, Case = 0, n, m, x, y;
    scanf("%d", &TC);
    while (TC--)
    {
        scanf("%d %d", &n, &m);
        point.clear();
        while (n--)
        {
            scanf("%d", &x);
            point.push_back(x);
        }
        printf("Case %d:\n", ++Case);
        while (m--)
        {
            scanf("%d %d", &x, &y);
             x = (int)(lower_bound(all(point), x) - point.begin());
            //cout <<"x" << x << endl;
            y = (int)(upper_bound(all(point), y) - point.begin());
            //cout <<"y" << y << endl;
 
            printf("%d\n", y - x);
        }
    }
    return 0;
}