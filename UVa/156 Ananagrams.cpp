#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <string> vec;
    vector <string>:: iterator it;
    char ch;
    int n,i;
    string s[1010],st[1010];
    int in = 0;
    while(scanf("%c",&ch)==1)
    {
        if(ch <= 'Z' && ch >= 'A'){st[in].push_back(ch);ch += 32; s[in].push_back(ch); }
        else if(ch <= 'z' && ch >= 'a'){st[in].push_back(ch);s[in].push_back(ch);}
        else{
        sort(s[in].begin(), s[in].end());
        //cout << s[in] << endl;
        in++;}
        if(ch == '#') break;
    }
    bool t;
    for(i = 0; i < in; i++)
    {
        t = 0;
        if(!s[i].empty()){
        for(int j = i+1; j < in; j++)
        {
            if(s[i] == s[j])
            {
                t = 1;
                s[j].clear();
            }
        }
        }
        if(t) {s[i].clear();}
    }
    for(i=0; i<in; i++)
    {
        if(!s[i].empty()) vec.push_back(st[i]);
    }
    sort(vec.begin(), vec.end());
    for(it = vec.begin(); it != vec.end(); it++)
    {
        cout << (*it) << endl;
    }
}
