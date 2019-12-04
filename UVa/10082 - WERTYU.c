#include<stdio.h>
#include<string.h>
int main()
{
    char input[500];
    int i,j,len;
    char key_1[50] = {' ','`','1','2','3','4','5','6','7','8','9','0','-','=','Q','W','E','R','T','Y','U','I','O','P','[',']','\\','A','S','D','F','G','H','J','K','L',';','\'','Z','X','C','V','B','N','M',',','.','/'};
    char key_2[50] = {' ','`','`','1','2','3','4','5','6','7','8','9','0','-','Q','Q','W','E','R','T','Y','U','I','O','P','[',']','A','A','S','D','F','G','H','J','K','L',';','Z','Z','X','C','V','B','N','M',',','.'};
    while(gets(input))
{
        len = strlen(input);
        for(i=0;i<len;i++)
        {
            for(j=0;j<48;j++)
            {
                if(input[i]==key_1[j]){printf("%c",key_2[j]);}
            }
        }
        printf("\n");
}
    return 0;
}

    //printf("\n\n%c",key_1[46]);
    /*scanf("%s[^\n]",&input);
    len=strlen(input);
    for(i=0;i<len;i++)
    {
        for(j=0;key[j]!='\0';j++){
        if(input[i]==key[j])
            {
                input[i]=key[j-1];
                printf("%c",key[j-1]);
            }
        }
    }
    printf("%s",input);*/
