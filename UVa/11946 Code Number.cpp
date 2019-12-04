///Not accepted Prob with string input
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str,s;
    int t,TC, q = 0;
    char c;
    cin >> TC;
    c = getchar();
    while(TC--)
    {
        if(q) cout << endl;
        while(getline(cin,str))
        {
            if(str.empty()) break;
            t =0;
            int len = str.size(), i;
            for(i = 0; i < len; i++)
            {
                s.clear();
                if(str[i] == '3')
                {
                    s = "E";
                }
                else if(str[i] == '0')
                {
                    s = "O";
                }
                else if(str[i] == '1')
                {
                    s = "I";
                }
                else if(str[i] == '2')
                {
                    s = "Z";
                }
                else if(str[i] == '4')
                {
                    s = "A";
                }
                else if(str[i] == '5')
                {
                    s = "S";
                }
                else if(str[i] == '6')
                {
                    s = "G";
                }
                else if(str[i] == '7')
                {
                    s = "T";
                }
                else if(str[i] == '8')
                {
                    s = "B";
                }
                else if(str[i] == '9')
                {
                    s = "P";
                }
                if(!s.empty()) str.replace(i,1,s);
            }
            if (t!=0) cout << endl;
            cout << str << endl;
            t = 1;
        }
        q = 1;
    }
}
