#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,cpy;
    while(cin >> s){
    cpy = s;
    int t = 0;
    do
    {
        t++;
//        cout << s << endl;
        if(t==11) break;
    }while(prev_permutation(s.begin(),s.end()));
//    cout << s << endl;
    t=0;
    int resd=-1;
    string ss;
    do
    {
        t++;
        int locm = 1111111;
//    cout << s << endl;
        for(int i=0; i<s.size()-1; i++)
        {
            locm = min(locm, abs(s[i]-s[i+1]));
        }
        if(resd<locm)
        {
            resd = locm;
            ss = s;
        }
//        cout << locm << endl;
        if(s==cpy) t = 11;
        if(t==21) break;
    }while(next_permutation(s.begin(),s.end()));
    cout << ss << resd << endl;
    }
}
