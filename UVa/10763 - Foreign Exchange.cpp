///Time Limit
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, n, i, cnt;
    multimap <int, int> Map;
    multimap <int, int> :: iterator it1, it2;
    while(cin >> n){
    Map.clear();
    if(!n) break;
    for(i=0; i<n; i++)
    {
        cin >> a >> b;
        Map.insert(pair<int, int> (a,b));
    }
    bool Yes = 1;
    for(it1 = Map.begin(); it1 != Map.end(); it1++)
    {
        a = it1->first;
        b = it1->second;
        cnt = Map.count(b);
        if(cnt <= 0){Yes = 0;}
        else
        {
            it2 = Map.find(b);
            int t = 0;
            while(cnt--)
            {
                int c =  (*it2).second;
                if(c==a) { t = 1;}
                //cout << (*it2).first <<" " << (*it2).second << endl;
                it2++;
            }
            if(!t) Yes = 0;
        }
        if(!Yes)break;
    }
    if(Yes) cout << "YES\n";
    else cout << "NO\n";
    }
}
