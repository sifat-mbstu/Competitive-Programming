#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k, len_1, len_2, TC;
    char str_1[120], str_2[120],c;
    char S1[105], S2[105], S3[105], S4[105], S5[105] ;
    scanf("%d",&TC);
    c = getchar();
    while(TC--)
    {
    gets(str_1);
    gets(str_2);

    len_1 = strlen(str_1);
    len_2 = strlen(str_2);

    k = 0;
    for(i=0; str_1[i] != '<' ; i++)
    {
        S1[i] = str_1[i];
    }
    S1[i] = '\0';
    j=0;
    i++;
    for( ; str_1[i]!='>'; i++)
    {
        S2[j] = str_1[i];
        j++;
    }
    S2[j] = '\0';
    i++;
    j=0;
    for( ; str_1[i] != '<' ; i++)
    {
        S3[j] = str_1[i];
        j++;
    }
    S3[j] = '\0';
    i++;
    j=0;
    for( ; str_1[i] != '>' ; i++)
    {
        S4[j] = str_1[i];
        j++;
    }
    S4[j] = '\0';
    i++;
    j=0;

    for( ; i<len_1 ; i++)
    {
        S5[j] = str_1[i];
        j++;
    }
    S5[j] = '\0';
    for(i=0;i<len_1 ; i++)
    {
        if(str_1[i] != '<' && str_1[i] != '>')
        {
             printf("%c",str_1[i]);
        }
    }
    printf("\n");
    for(i=0; i<len_2; i++)
    {
        if(str_2[i] == '.')
        {
            printf("%s%s%s%s",S4,S3,S2,S5);
            break;
        }
        printf("%c",str_2[i]);
    }
    printf("\n");
    }
}
