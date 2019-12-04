///Incompleted
#include<bits/stdc++.h>
using namespace std;
int main()
{
    map <string ,int> Map;
    string s[1010],str[1010],cpy;
    int n, Max, i, j;
    cin >> n;
    Max = 0;
    for(i=0; i<n; i++)
    {
        cin >> s[i];
        if(Max < s[i].size())
        {
            Max = s[i].size();
        }
    }
    int sum = 0,k=0;
    for(i=0; i < Max; i++)
    {
        Map.clear();
        for(j=0; j<n; j++) str[j].clear();

        for(j=0; j<n; j++){
            int len = s[j].size(), p;
         if(len < i){p = len;}
         else{p = i;}
         if(!s[j].empty()){
         str[j].insert(0,s[j],0,p);
         Map[str[j]]++;
         }
         //cout << str[j ] << endl;
        }
        for(j=0; j<n; j++)
        {
            cout << Map[str[j]] << endl;
            if( !str[j].empty() && Map[str[j]] == 1)
            {
                k++;
                sum += str[j].size();
            }
            s[j] = "";
        }
    }
    cout << sum << endl;
}
