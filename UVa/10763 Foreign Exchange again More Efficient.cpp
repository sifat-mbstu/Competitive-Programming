#include<bits/stdc++.h>
using namespace std;
#define maxx 500010
int a[maxx], b[maxx];
int main()
{
    int i, j, n,n1, n2;
    while(cin >> n)
    {
        if(!n) break;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        j = 0;
        for(i=0; i<n; i++)
        {
            scanf("%d %d",&a[i], &b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);
        int Yes = 1;
        for(i = 0; i < n; i++)
        {
            if(a[i] != b[i]) Yes = 0;
        }
        if(Yes) cout << "YES\n";
        else cout << "NO\n";
    }
}
