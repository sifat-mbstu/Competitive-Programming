#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[20],b[20],i,j,x=0,n;
    while(cin >> n)
    {
        a[0] = n;
        if(n < 0) break;
    for(i=1;i<=12;i++) cin >> a[i];
    for(i=0;i<12;i++) cin >> b[i];
     printf("Case %d:\n",++x);
    for(i = 0; i < 12; i++)
    {
        if(a[i] >= b[i])
        {
            a[i+1] += (a[i] -b[i]);
            printf("No problem! :D\n");
        }
        else
        {
            a[i+1] += a[i];
            printf("No problem. :(\n");
        }
    }
    }
}
