#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[10];
    int len;
    float M,H,a,b;
    while(gets(str))
    {
        len = strlen(str);
        if(len==5)
        {
            M = (str[4] - '0') + (str[3] - '0')*10;
            H = (str[0] - '0')*10 + (str[1] - '0');
        }
        else
        {
            M = (str[2]-'0')*10 + (str[3] - '0');
            H = str[0] - '0' ;
        }
        if((H+M)==0)
        {
            break;
        }
        //printf("H=%f M=%f",H,M);
        a = H * 30 + .5 * M;
        b = M * 6 ;
        M = abs(a - b);
        if(M>=180)
        {
            M=M-360;
        }
        M = abs(M);
        printf("%.3f\n",M);
    }
    return 0;
}
