#include<bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("out.txt","w",stdout);
    int TC, ind = 0;
    cin >> TC;
    while(TC--)
    {
        vector <string> V;
        int cur=1;
        V.push_back("http://www.lightoj.com/");
        string s,str;
        printf("Case %d:\n",++ind);
        while(cin >> s)
        {
           // cout << cur << endl;
            if(s == "VISIT")
            {
                while(V.size()!= cur) V.erase(V.begin()+cur);
                cin >> str;
                cout << str << endl;
                V.push_back(str);
                cur = V.size();
            }
            else if(s == "BACK")
            {
                if(cur < 2) printf("Ignored\n");
                else
                {
                    cout << V[cur-2] << endl;
                    cur--;
                }

            }
            else if(s == "FORWARD")
            {
                if( (cur+1) > (V.size()) ) printf("Ignored\n");
                else
                {
                    cout << V[cur] << endl;
                    cur++;
                }
            }
            else if(s == "QUIT")
            {
                break;
            }
        }
    }
}
