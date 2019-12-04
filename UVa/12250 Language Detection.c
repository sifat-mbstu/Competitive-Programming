#include<stdio.h>
#include<string.h>
#define max 16
int main()
{
    char str[max];
    int N=0;
    while((scanf("%s",&str)==1) && (strcmp(str,"#")!=0))
    {
    if(strcmp(str,"HELLO")==0) {printf("Case %d: ENGLISH\n",++N);}
    else if((strcmp(str,"HOLA"))==0) {printf("Case %d: SPANISH\n",++N);}
    else if(strcmp(str,"HALLO")==0) {printf("Case %d: GERMAN\n",++N);}
    else if(strcmp(str,"BONJOUR")==0) {printf("Case %d: FRENCH\n",++N);}
    else if(strcmp(str,"CIAO")==0) {printf("Case %d: ITALIAN\n",++N);}
    else if(strcmp(str,"ZDRAVSTVUJTE")==0) {printf("Case %d: RUSSIAN\n",++N);}
    else {printf("Case %d: UNKNOWN\n",++N);}
    }
    return 0;
}
