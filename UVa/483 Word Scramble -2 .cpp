#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[10000];
    int i,len,j,k;
    gets(str);
    len = strlen(str);
    for(i=0,k=0;i<len+1; i++,k++)
    {
        if(str[i]==' ' || i == len)
        {
            k--;
            j = i+1;
            while(j--)
                {
                    if(str[k]==' '){break;}
                    printf("%c",str[k]);
                    k--;

                }
        }
        k=i;
        if(i==len-1){i++;}
    }
}
