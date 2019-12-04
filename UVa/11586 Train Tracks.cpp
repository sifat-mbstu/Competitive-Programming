#include<bits/stdc++.h>
using namespace std;
int main()
{
    int TC ,i,j, len,Loop,k,F,M;
    char str[1000],Fin[1000],c;
    scanf("%d",&TC);
    c = getchar();
    while(TC--)
    {

    gets (str);
    Loop = F =M = 0;
    len = strlen(str);
    j = 0;
    for(i=0;i<len;i++)
    {
        while(str[i]==' '){i++;}
        j++;
        Fin[j-1] = str[i];
    }
    //printf("j = %d\n",j);
    if(j<=2){Loop = 0;}
    else
    {
        for(i=0;i<j;i+=2)
        {
            if(Fin[i] == Fin[i+1])
            {
             if(Fin[i]=='F'){F++;}
             else {M++;}
            }
        }

    if(F==M) {Loop = 1;}
    }
    if(Loop){printf("LOOP\n");}
    else {printf("NO LOOP\n");}
    }
}
