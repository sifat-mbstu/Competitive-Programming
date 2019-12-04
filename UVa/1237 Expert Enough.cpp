#include<bits/stdc++.h>
using namespace std;
int main()
{
    bool t = 1;
    int TC, i, n, a, b,cnt, val, m;
    string s,res;
    pair<int,int> P;
    map <string, pair<int, int> > Map;
    map <string, pair<int, int> > :: iterator it;
    cin >> TC;
    while(TC--){
    if(!t) cout << endl;
    cin >> n;
    Map.clear();
    for(i=0; i<n; i++)
    {
        cin >> s >> a >> b;
        //cout << s << a << b << endl;
        Map[s] = make_pair(a,b);
    }
    cin >> m;
    for(i=0; i<m; i++)
    {
        cnt = 0;
        cin >> val;
        for(it=Map.begin(); it != Map.end(); it++)
        {
            s = it->first;
            P = it->second;
            int a = P.first;
            int b = P.second;
            if(val >= a && val <= b)
            {
            //    cout << a <<"=a ...   b =" << b << endl;
                cnt++;
                if(cnt > 1) break;
                res = s;
            }
        }
        if(cnt == 1){cout << res << endl;}
        else{cout << "UNDETERMINED" << endl;}
        t=0;
    }
    }
}
