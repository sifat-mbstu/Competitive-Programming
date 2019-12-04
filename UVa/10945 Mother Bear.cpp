#include<bits/stdc++.h>
using namespace std;
#define max 1000000
char str[max],str_1[max],str_2[max];
int main()
{
    int test,len,i,j,k;
    while(gets(str))
    {
        if(strcmp(str,"DONE")==0)
        {
            break;
        }
        len = strlen(str);
        j=test=0;
        for(i=0; i<len; i++)
        {
            if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z'))
            {
                //printf("j==%d\n",j);
                if(str[i]>='A' && str[i]<='Z')
                {
                    str[i]=str[i]+32;
                }
                str_1[j]=str[i];
                j++;
            }
            else
            {
                continue;
            }
        }
        len = j;
        //puts(str_1);
        k=0;
        for(i=j-1; i>=0; i--)
        {
            str_2[k]=str_1[i];
            //printf("%c",str_1[i]);
            k++;
        }
        //puts(str_2);
        for(i=0; i<j; i++)
        {
            if(str_1[i]!=str_2[i])
            {
                test=1;
                break;
            }
        }
        if(test)
        {
            printf("Uh oh..\n");
        }
        else
        {
            printf("You won't be eaten!\n");
        }
    }
    return 0;
}
