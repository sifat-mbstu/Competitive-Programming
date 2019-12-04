#include <bits/stdc++.h>
using namespace std;
int main()
{
    int len,i,counts =0,t,num;
    char str[2010];
    while(gets(str))
    {

    if(strcmp(str, "*")==0){break;}
    t = 1;
    len = strlen(str);
    if(str[0] >= 'a' && str[0] <= 'z')
    {
        num = str[0] - 32;
    }
    else{num = str[0];}

    for(i=0; i<len; i++)
    {
        if(str[i]==' '){
            if(str[i+1] != num && str[i+1] != num+32)
            {
                t =0;
                break;
            }
        }
    }
    if(t) {printf("Y\n");}
    else {printf("N\n");}
    }
}
