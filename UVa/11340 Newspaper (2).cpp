#include<bits/stdc++.h>
using namespace std;
map<char,int>Map;
int main()
{
    int TC;
    scanf("%d",&TC);
    while(TC--){
    Map.clear();
    int k,val;
    char ch;
    scanf("%d",&k);
    while(k--)
    {
        getchar();
        scanf("%c %d",&ch,&val);
//        cout << ch << " " << val << endl;
        Map[ch] = val;
    }
    int m;
    scanf("%d",&m);
    getchar();
    double sum = 0.0;
    while(m--)
    {
        string s;
        getline(cin,s);
        for(int i=0; i<s.size(); i++)
        {
            if(Map.find(s[i])!=Map.end()) sum += Map[s[i]];
        }
//        cout <<"=>" << s << endl;
    }
    sum = sum/100;
    printf("%.2lf$\n",sum);
    }
}
