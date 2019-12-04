#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int i=0;
    char Hajj[20];
    while(gets(Hajj))
    {
        i++;
    if(strcmp(Hajj,"Hajj")==0){printf("Case %d: Hajj-e-Akbar\n",i);}
    else if(strcmp(Hajj,"Umrah")==0){printf("Case %d: Hajj-e-Asghar\n",i);}
    else if(Hajj[0]=='*'){break;}
    }
    return 0;
}
