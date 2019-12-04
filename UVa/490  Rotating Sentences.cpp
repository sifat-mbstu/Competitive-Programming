#include <bits/stdc++.h>
using namespace std;
int main ()
{
    char str[105][105];
    int i, j,k, MAX, len,total;
     for (i = 0; i < 105; i++) {
        for (j = 0; j < 105; j++)
            str[i][j] = ' ';
     }
    total = 0;

    while(gets(str[total])) total++;

    MAX = 0;

    for(j=0; j< total; j++)
    {
        len = strlen(str[j]);
        if(len > MAX)
        {
            MAX = len;
        }
        str[j][len] = ' ';
    }

    for(j=0; j<MAX; j++)
    {
        for(k=total-1; k>=0; k--)
        {
            printf("%c",str[k][j]);
        }
        printf("\n");
    }
    return 0;
}
