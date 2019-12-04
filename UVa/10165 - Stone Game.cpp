#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cs = 0,n,u,ans,cnt,i;

    while(cin >> n){
            if(!n){break;}
        scanf("%d",&ans);
        for(i = 1; i < n; i++){
            cin >> u;
            ans = ans^u;
            //cout << ans <<endl;
        }
        if(!ans) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}
