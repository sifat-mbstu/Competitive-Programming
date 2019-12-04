#include<bits/stdc++.h>
using namespace std;
int main()
{
    map <char, int> Id;
    string s;
    while(cin >> s){
    for(int i='a'; i<='z'; i++){Id[i] = -1;}
    int j=1,k;
    for(int i=0;i<s.size();i++)
    {
        //cout << Id[s[i]]<< "= ID  .... s[i] =" << s[i] << " ID[s[i]] later = ";
        if(Id[s[i]] == -1){
                if(j==5){k=2;}
                else if(j==2){k=5;}
                else if(j==6){k=9;}
                else if(j==9){k=6;}
                else if (j==12){k=15;}
                else if (j==15){k=12;}
                else if (j==16){k=19;}
                else if (j==19){k=16;}
                else if(j==20 || j==21 || j ==23 || j == 24){k = j+30;}
                else if (j == 22){k = 55;}
                else if (j==25){k = 52;}
                else if (j==26){k = 59;}
                else {k = j;}
                Id[s[i]] = k;
                j++;
        }
        //cout << Id[s[i]] << endl;
        }
    //cout << s << endl;
    for(int i=0;i<s.size();i++)
    {
         cout << Id[s[i]];
    }
    cout << endl;
    }
}
