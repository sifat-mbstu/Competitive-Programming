#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int gcd = 0;

pii ext_gcd(int a, int b)
{
    int q = 0, r0 = a, r1 = b, x0 = 1, y0 = 0, x1 = 0, y1 = 1;
    int x = 0, y = 1;

    while(1)
    {
        q = r0/r1;
        int r = r0%r1;
        if(r==0)break;
        r0 = r1;
        r1 = r;
        x = x0 - x1*q;
        y = y0 - y1*q;
        x0 = x1; y0 = y1;
        x1 = x; y1 = y;
    }
    gcd = r1;
    return make_pair(x,y);
}
int main()
{
    int a,b;
    while(cin >> a >> b){
    pii ans = ext_gcd(a,b);
    int x = ans.first;
    int y = ans.second;
    printf("%d %d %d\n",x,y,gcd);
    }
}
