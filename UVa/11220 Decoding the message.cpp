#include<bits/stdc++.h>
using namespace std;
#define FI freopen("input.txt", "r", stdin)
#define FO freopen("output.txt", "w", stdout)
int main()
{
    //FO;
    int TC,t=0,i;
    string s,words, str;
    scanf("%d\n\n",&TC);
    for(i=1; i<= TC; i++){
    if(i>1) cout << endl;
    printf("Case #%d:\n",i);
    while(getline(cin,s))
    {
        int j = 0;
        //cout << s << endl;
        if(s.empty()) {break;}
        stringstream ss;
        ss << s;
        while(ss >> words)
        {
            if(j<words.size()) str.push_back(words[j++]);
        }
        cout << str << endl;
        str.clear();
    }
    }
}
