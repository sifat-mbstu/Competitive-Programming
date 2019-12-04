#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    string s[100000];
    int i=0,j,Max =0,ara[400000],k;
    memset(ara, 0, sizeof(ara));
    while(getline(cin,s[i]))
    {
        if(s[i] == "#")
        {
            break;
        }
        if(Max < s[i].size())
        {
            Max = s[i].size();
        }
        i++;
    }
    for(j = 0; j < Max; j++)
    {
        for(k=0; k<i; k++)
        {
            if(s[k].size() > j )
            {
                c = s[k][j];
                if(ara[c] == 0)
                {
                    printf("%c",c);
                }
                ara[c] = 1;
            }
        }
    }
    printf("\n");
}
