#include<stdio.h>
#include<string.h>
int main()
{
    char str[3000];
    int num,len,i;
    while(gets(str))
    {
    len = strlen(str);
    for(i=0;i<len;i++)
    {
        num=str[i];
        if(num<=67 && num>=65){printf("2");}
        else if(num<=70 && num>=68){printf("3");}
        else if(num<=73 && num>=71){printf("4");}
        else if(num<=76 && num>=74){printf("5");}
        else if(num<=79 && num>=77){printf("6");}
        else if(num<=83 && num>=80){printf("7");}
        else if(num<=86 && num>=84){printf("8");}
        else if(num<=90 && num>=87){printf("9");}
        else{printf("%c",str[i]);}
    }
    printf("\n");
    }
    return 0;
}
