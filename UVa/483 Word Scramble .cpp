#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[9000];
    int i,t,j,len;
    while(gets(str))
    {
        t=-1;
    len = strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]==' ')
        {

            for(j=i-1;j>t;j--)
            {
                printf("%c",str[j]);
            }
            printf(" ");
            t = i;
        }
    }
    for(i=len-1;i>t;i--)
            {
                printf("%c",str[i]);
            }
    printf("\n");

    }
    return 0;
}
