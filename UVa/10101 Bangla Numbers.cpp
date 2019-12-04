#include<bits/stdc++.h>
using namespace std;
int main()
{
    int len,i,ara[20],n = 1,k;
    char str[20];
    for(i=0;i<10;i++)
    {
        ara[i] = 0;
    }
    gets(str);
    len = strlen(str);
    k = len;
    for(i=0;i<len;i++)
    {

    /*if(k-15 >= 0){n=1; ara[8] += (str[k-15] - '0')*n; n *= 10; k--;}

    else if(k-14 >= 0){ n=1; ara[7] += (str[k-14] - '0')*n; n *= 10; k--;}
    else if(k-13 >= 0){ ara[7] += (str[k-13] - '0')*n; n *= 10;k--; }

    else if(k-12 >= 0){n=1; ara[6] += (str[k-12] - '0')*n; n *= 10; k--;}
    else if(k-11 >= 0){ ara[6] += (str[k-11] - '0')*n; n *= 10;k--; }

    else if(k-10 >= 0){n=1; ara[5] += (str[k-10] - '0')*n; n *= 10; k--;}

    else if(k-9 >= 0){n=1; ara[4] += (str[k-9] - '0')*n; n *= 10;k--; }
    else if(k-8 >= 0){ ara[4] += (str[k-8] - '0')*n; n *= 10; k--;}

    else if(k-7 >= 0){n=1;ara[3] += (str[k-7] - '0')*n; n *= 10;k--; }
    else if(k-6 >= 0){ ara[3] += (str[k-6] - '0')*n; n *= 10; k--;}

    else if(k-5 >= 0){n=1; ara[2] += (str[k-6] - '0')*n; n *= 10;k--; }
    else if(k-4 >= 0){ara[2] += (str[k-5] - '0')*n; n *= 10; k--;}

    else if(k-3 >= 0){n=1; ara[1] += (str[k-3] - '0')*n; n *= 10;k--; }*/

    if(k-2 >= 0){n=1; ara[0] += (str[k-2] - '0')*n; n *= 10; k--;}
    //else if(k-1 >= 0){ara[0] += (str[k-1] - '0')*n; n *=10;k--;}
}
    for(i=0;i<=0;i++)
    {
        printf ("i = %d\n",ara[i]);
    }
}
