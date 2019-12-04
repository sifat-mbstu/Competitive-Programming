///AC
#include<bits/stdc++.h>
using namespace std;
struct st
{
    int x1,y1,z1;
    int x2,y2,z2;
} arr[220];

int main()
{
    int TC,idx=0;
    scanf("%d",&TC);
    while(TC--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            int x1,x2,y1,y2,z1,z2;
            scanf("%d %d %d %d %d %d",&arr[i].x1,&arr[i].y1,&arr[i].z1,&arr[i].x2,&arr[i].y2,&arr[i].z2);
        }
        int xlo = 0, ylo = 0, zlo = 0;
        int xhi = 2000, yhi = 2000, zhi = 2000;
        for(int i=0; i<n; i++)
        {
            xlo = max(xlo,arr[i].x1);
            xhi = min(xhi,arr[i].x2);

            ylo = max(ylo,arr[i].y1);
            yhi = min(yhi,arr[i].y2);

            zlo = max(zlo,arr[i].z1);
            zhi = min(zhi,arr[i].z2);
        }

        int res = (xhi-xlo) * (yhi-ylo) * (zhi-zlo);
        if(xhi<=xlo || yhi <= ylo || zhi <= zlo) res = 0;

        printf("Case %d: %d\n",++idx,res);
    }
}
