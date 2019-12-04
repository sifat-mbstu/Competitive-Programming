#include<stdio.h>
int main()
{
    int i,j;
    char ori[100],rev[100];
    while((gets(ori))!= EOF)
    {
        i=0,j=0;
        while(ori[i] != '\0')
        {
            if(ori[i] != ' ')
            {
                rev[j]=ori[i];
                j++;
            }
            else
            {
                rev[j]='\0';
                printf("%s",strrev(rev));
                printf(" ");
                j=0;
            }
            i++;
        }
        rev[j]='\0';
        printf("%s\n",strrev(rev));
    }
    return 0;
}
