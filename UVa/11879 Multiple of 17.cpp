#include<bits/stdc++.h>
using namespace std;
int main()
{
    int len,rem,sum,i;

    char str[1060];

    while(gets(str))
    {
        if(strcmp(str,"0")==0){break;}
        len = strlen(str);
        rem = 0 ;
        for(i=0; i<len; i++)
        {
            sum = rem * 10 + (str[i]-'0');

            rem = sum % 17;
        }
        if(rem)
        {
            printf("0\n");
        }
        else
        {
            printf("1\n");
        }
    }
}
