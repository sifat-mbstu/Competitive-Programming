#include<stdio.h>
#include<string.h>
#include<stdlib.h>
# define max 10000
int main()
{
    char str[max];
    long int N,n;
    scanf("%ld",&N);
    do{
    gets(str);
    n=strlen(str);
    if(strcmp(str,"1")==0 || strcmp(str,"4")==0 || strcmp(str,"78")==0){printf("+\n");}
    else if(str[n-1]=='5' && str[n-2]=='3'){printf("-\n");}
    else if(str[0]=='9' && str[n-1]=='4'){printf("*\n");}
    else if(str[0]=='1' && str[1]=='9'&& str[2]=='0'){printf("?\n");}
    else{};
    }
    while(N--);
    return 0;
}
