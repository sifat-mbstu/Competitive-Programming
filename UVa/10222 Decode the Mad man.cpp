#include<bits/stdc++.h>
using namespace std;
int main()
{
    char input[500];
    int i,j,len;
    char key_1[50] = {' ','2','3','4','5','6','7','8','9','0','-','=','e','r','t','y','u','i','o','p','[',']','\\','d','f','g','h','j','k','l',';','\'','c','v','b','n','m',',','.','/'};
    char key_2[50] = {' ','`','1','2','3','4','5','6','7','8','9','0','q','w','e','r','t','y','u','i','o','p',';','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m',','};
    while(gets(input))
{
        len = strlen(input);
        for(i=0;i<len;i++)
        {
            if(input[i] >= 65 && input[i] <= 90){input[i]  += 32;}
            for(j=0;j<48;j++)
            {
                if(input[i]==key_1[j]){printf("%c",key_2[j]);}
            }
        }
        printf("\n");
}
    return 0;
}
