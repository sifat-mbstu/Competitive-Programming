///Accepted
#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<char,int>Map;
    map<char,int> :: iterator it;
    int n,i, Max;
    char str[1212120],c;
    cin >> n;
    Max = 0;
    c = getchar();
    while(n--)
    {
        gets(str);
        int len = strlen(str);
        for(i=0; i<len; i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                c = str[i] - 32;
                Map[c]++;
            }
            else if(str[i] >= 'A' && str[i] <= 'Z')
            {
                c = str[i] ;
                Map[c]++;
            }
            if(Max < Map[c]){ Max = Map[c];}
        }
    }
    for(i = Max; i>=0; i--){
    for(it = Map.begin(); it != Map.end(); it++)
    {
        if(((*it).second) == i){
        cout << (*it).first << " " << (*it).second << endl;
        }
    }
    }
}
