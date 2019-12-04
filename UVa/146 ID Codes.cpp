#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    while(cin >> str)
    {
        if (str == "#") break;
        int len = str.size(), s = 0;
        if(len <= 50){
        for(int i=0; i<len-1; i++)
        {
            if(str[i] < str[i+1])
            {
                s = 1;
                break;
            }
        }
        }
        if(s)
        {
            for(i=len-1; i>= 0; i++)
            {

            }
        }
            cout << str << endl;
        else printf("No Successor\n");
    }
}
