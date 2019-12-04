#include<bits/stdc++.h>
using namespace std;
int fx[] = {0,0,0,1,-1};
int fy[] = {0,1,-1,0,0};
int main()
{

    int r,c,n,px[3010], py[3010], idx=0;
    while(scanf("%d %d %d",&r, &c, &n)==3){
    if(!r && !c && !n)break;
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&px[i], &py[i]);
    }
    int ax,ay;
    scanf("%d %d",&ax, &ay);
    bool escape = 0;
    for(int i=0; i<5; i++)
    {
        int nx = ax+fx[i];
        int ny = ay+fy[i];
        if(nx<0 || nx >= r || ny <0 || ny>=c) continue;
        bool hobe = 1;
        for(int j=0; j<n; j++)
        {
            if(nx==px[j]){hobe = 0; }
            if(ny==py[j]){hobe = 0; }
            if(!hobe)break;
//            if(hobe==0) {cout << nx << " " ny << endl;}
        }
        if(hobe) {escape = 1;break;}
    }
    if(escape) printf("Case %d: Escaped again! More 2D grid problems!\n",++idx);
    else printf("Case %d: Party time! Let's find a restaurant!\n",++idx);
    }
}
