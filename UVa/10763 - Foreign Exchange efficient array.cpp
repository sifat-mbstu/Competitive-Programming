#include<bits/stdc++.h>
using namespace std;
#define maxx 500010
int a[maxx], b[maxx];
set <int> SET;
set <int>  :: iterator it;
int main()
{
    int i, j, n,n1, n2;
    while(cin >> n){
    if(!n) break;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    SET.clear();
    j = 0;
    for(i=0; i<n; i++)
    {
        scanf("%d %d",&n1, &n2);
        SET.insert(n1);
        SET.insert(n2);
        a[n1]++;
        b[n2]++;
    }
    int Yes = 1;
    for(it = SET.begin(); it!= SET.end(); it++)
    {
        int z =(*it);
        if(a[z] != b[z]) {Yes = 0; break;}
    }
    if(Yes) cout << "YES\n";
    else cout << "NO\n";
    }
}
