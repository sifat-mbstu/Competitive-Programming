#include<bits/stdc++.h>
using namespace std;
int main()
{
    map <string, int> Map;
    map <string, int> :: iterator it;
    int n, i;
    string s,str,pass;
    while(cin >> n >> s){
    Map.clear();
    int len = s.size();
    for(i=0; i<len-n-1; i++)
    {
         str.insert(0,s,i,n);
       //  cout << str << endl;
         Map[str]++;
         str.clear();
    }
    int Max = 0;
    for(it = Map.begin(); it != Map.end(); it++)
    {
        int a = (*it).second;
        if(a > Max)
        {
            Max = a;
            pass = (*it).first;
        }
    }
    cout << pass << endl;
    }
}
