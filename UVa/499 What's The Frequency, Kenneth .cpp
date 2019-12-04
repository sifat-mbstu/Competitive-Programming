#include<bits/stdc++.h>
using namespace std;
int alp[1000] = {0};
int main()
{
    char str[100000],I ;
    int len,i,Max;

    while(gets(str))
    {
    len = strlen(str);
    for(i=0;i<len;i++)
    {
        if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
                alp[str[i]]++;
    }
    Max = 0;
    for(i=65;i<=122;i++)
    {
        if(Max < alp[i]){ Max = alp[i];}
    }

    for(i=65;i<=122;i++)
    {
        if(Max == alp[i]) {
                printf("%c",i);}
    }
    printf(" %d\n",Max);
    memset( alp, 0, sizeof(alp));
    }
}
