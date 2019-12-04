
///Not accepted
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,len,TC,True;
    char s[200],c;

    scanf("%d",&TC);
    c = getchar();
    while(TC--)
    {
        True = 1;
        fgets(s, sizeof(s),stdin);
        len = strlen(s);
        s[len-1] = '\0';
        len--;
        n = len - 2;
        if(len == 0) {True = 0; break;}
        else if(len % 2 != 0) {True = 0;}
        else
        {
            len = len/2;
            for(i=0; i<len; i++)
            {
                if(s[i] == '[' && s[n-i] != ']')
                {
                    True = 0;
                    break;
                }
                else if(s[i] == '(' && s[n-i] != ')')
                {
                    True = 0;
                    break;
                }
            }
        }
        if(True){printf("Yes\n");}
        else {printf("No\n");}
    }
}
