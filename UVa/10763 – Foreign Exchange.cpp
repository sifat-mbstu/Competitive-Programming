#include<bits/stdc++.h>
using namespace std;
int main()
{
    map <pair < int,int > , int> Map;
    map <pair < int,int > , int> :: iterator it;
    int n, a, b,i;
    while(cin >> n){
        if(!n) break;
    Map.clear();
    pair <int, int> p1, p2;
    for(i=0; i<n; i++)
    {
        cin >> a >> b;
        p2 = make_pair(a,b);
        Map[p2]++;
    }
    bool Yes = 1;
    for(it = Map.begin(); it != Map.end(); it++)
    {
        p1 = p2 = it-> first;
        swap(p2.first, p2.second);
        if(Map[p2] != Map[p1]) {Yes = 0;break;}
    }
    if(Yes) cout << "YES\n";
    else cout << "NO\n";
    }
}
