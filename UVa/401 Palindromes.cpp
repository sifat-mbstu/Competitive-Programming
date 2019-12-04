#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,fin,len,mir_palis,reg_pal,mir_str;
    char str[30];
    char Mir_pali[30] = {'A', 'H', 'I', 'L', 'J', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y', '1', '8'};
    char Mir_str_1[10] = {'E', 'L', 'Z', '2', '3', 'J', '5', 'S'};
    char Mir_str_2[10] = {'3', 'J', '5', 'S', 'E', 'L', 'Z', '2'};
    while(gets(str))
    {
        reg_pal = mir_palis = mir_str = 0;
        len = strlen(str);

        if(len%2==0)
        {
            fin = len/2;
        }
        else
        {
            fin = (len+1)/2;
        }
        //printf("Len = %d Fin = %d\n",len,fin);
        for(i=0; i<fin; i++)
        {
            if(str[i]==str[len-i-1])
            {
                //printf("str[i] = %c\n",str[i]);
                reg_pal++;
                for(j=0; j<15; j++)
                {
                    if(Mir_pali[j] == str[i])
                    {
                        mir_palis++;
                        break;
                    }
                }
                //printf("mir_pallis = %d\n",mir_palis);
            }
            else if(str[i]!=str[len-i-1])
            {
                for(j=0; j<8; j++)
                {
                    if(Mir_str_1[j]==str[i])
                    {
                        if(Mir_str_2[j]==str[len-i-1])
                        {
                            mir_str++;
                            break;
                        }
                    }
                }
            }
        }
        //printf("mir_pallis = %d\n",mir_palis);
        if(mir_palis == fin)
        {
            printf("%s -- is a mirrored palindrome.\n\n",str);
        }
        else if(reg_pal == fin)
        {
            printf("%s -- is a regular palindrome.\n\n",str);
        }
        else if((reg_pal+mir_str) == fin)
        {
            printf("%s -- is a mirrored string.\n\n",str);
        }
        else
        {
            printf("%s -- is not a palindrome.\n\n",str);
        }
    }
    return 0;
}
