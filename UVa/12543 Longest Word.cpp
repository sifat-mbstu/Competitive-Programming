#include<bits/stdc++.h>
using namespace std;
#define FI freopen("input.txt", "r", stdin)
#define FO freopen("output.txt", "w", stdout)
int main()
{
    //FI;
    int Max=0,j = 0;
    char str[200],c, res[200];
    while(scanf("%c",&c)==1)
    {
        if((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A') || c == '-')
        {
            //printf("c=%c\n",c);
            str[j] = c;
           //printf("str[%d] =%c.\n",j, str[j]);
            j++;
        }
        else{
            str[j] = '\0';
            int len = strlen(str);
            if(strcmp(str, "E-N-D")==0){break;}
            if(Max < len){ Max = len; strcpy(res, str);}
            j = 0;
            //cout << str << endl;
        }
    }
    for(int i=0;i<Max;i++)
    {
        if(res[i] <= 'Z' && res[i] >= 'A')
        {
            res[i] = res[i] + 32;
        }
    }
    printf("%s\n",res);

    return 0;
}
