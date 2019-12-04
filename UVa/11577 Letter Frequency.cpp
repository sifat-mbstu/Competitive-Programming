#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[210],c;
    int i, len, ara[30],MX,num, TC;
    scanf("%d",&TC);
    c = getchar();
    while(TC--)
    {
        gets(str);
        MX =0;
        len = strlen(str);
        for(i=0; i<28; i++)
        {
            ara[i] = 0;
        }
        for(i=0; i<len; i++)
        {
            if(str[i] <= 'z' && str[i] >= 'a')
            {
                num = str[i] - 'a';
                ara[num]++;
            }
            else if(str[i] <= 'Z' && str[i] >= 'A')
            {
                num = str[i] - 'A';
                ara[num]++;
            }
        }

        for(i=0; i<26; i++)
        {
            if(ara[i] > MX) MX = ara[i];
        }
        for(i=0; i<26; i++)
        {
            if( MX == ara[i])
            {
                printf("%c",i + 'a');
            }
        }
        printf("\n");
    }
    return 0;
}
