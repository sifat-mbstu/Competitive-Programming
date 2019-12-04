#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
map<string,int>Mp;
string ss[210000];
void process(string now)
{
    stringstream sst;
    for(int i=0; i<now.size(); i++)
    {
        if(now[i]=='(') now[i] = ' ';
        else if(now[i]==')') now[i] = ' ';
        else if(now[i]==',') now[i] = ' ';
    }
    int v;
    string p;
    sst << now;
    sst >> v;
    sst >> p;
//    if(v==5) cout << p.size() << endl;
    Mp[p]=v;

//  ss[cnt] = p;
}
vector<int>lev[210000];
int chk = 0;
void rec(string s)
{
    if(Mp.find(s)==Mp.end()) return;
    int l = s.size();
    int v = Mp[s];
    chk++;
    lev[l].push_back(v);
    rec(s+'L');
    rec(s+'R');
}
int main()
{
    string s;
    while(getline(cin,s))
    {
        stringstream ss;
        ss << s;
        string now;
        while(ss >> now)
        {
            if(now.size()==2)
            {
                ///result
                ///clear all
                rec("");
                if(chk != cnt)
                {
                    cout << "not complete" << endl;
                }
                else
                {
                    for(int i=0; ; i++)
                    {
                        if(lev[i].size()==0) break;
                        if(i==0) cout << lev[i][0] ;
                        else cout << " " << lev[i][0] ;
                        for(int j=1; j<lev[i].size(); j++)
                        {
                            cout << " " << lev[i][j];
                        }
                        lev[i].clear();
                    }
                    cout << endl;
                }
                    for(int i=0; i<200000;i++) lev[i].clear();
                Mp.clear();
                cnt = 0;
                chk= 0;
                continue;
            }
            else
            {
                process(now);
                cnt++;
            }

        }
    }
}
