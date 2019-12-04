#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s))
    {
        bool flag = 0;
                string ss[100000];
                string pp = "";
//        deque<char>dq;
        int idx = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='[') {flag = 1;continue;}
            if(s[i]==']') {flag = 0;continue;}
            if(flag)
            {
                while(i<s.size() && s[i]!=']')
                {
                    if(s[i]=='['){idx++;i++;continue;}
                    ss[idx] += s[i];
                    i++;
                }
                idx++;
                i--;
//                cout << ss << endl;
//                for(int j=ss.size()-1; j>=0; j--){
//                dq.push_front(ss[j]);
//                }
            }
            else
            {
                pp += s[i];
            }
        }
//        reverse(ss.begin(),ss.end());
        for(int i = idx-1; i>=0; i--)
            cout<< ss[i];
        cout <<  pp << endl;
    }
}
