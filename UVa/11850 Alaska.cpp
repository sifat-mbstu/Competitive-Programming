#include<bits/stdc++.h>
using namespace std;
#define FI freopen ("input.txt", "r", stdin);
#define FO freopen ("output.txt", "w", stdout);
int main()
{
    //FI;
    int n, a[2000], pos = 1,i;
    while(cin >> n)
    {
        if(!n){break;}
        pos = 1;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a,a+n);
        for(i = 0; i< n-1; i++)
        {
            int dif = abs(a[i+1] - a[i]);
            if(dif > 200){pos = 0; break;}
        }
        if(((a[0] - 0)*2 > 200) || ((1422 - a[i])*2 > 200)){pos = 0;}
        if(pos) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }

}
