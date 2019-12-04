#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    char str[1000],c;
    int i,j,k,len,num;
    while(gets(str)){

    len = strlen(str);
    for(i=0;i<len;i++)
    {
        num = 0;
        if(str[i] <= '9' && str[i] >= '0')
        {
            num = str[i] - '0';
            while(str[i+1] <= '9' && str[i+1] >= '0')
            {
                num += (str[i+1] - '0');
                i++;
            }
            if(str[i+1] == 'b'){ c = ' ';}
            else { c = str[i+1];}
            i++;
            while(num--){ printf("%c",c);}
        }
        else {printf("\n");}
    }
    printf("\n");
    }
}
