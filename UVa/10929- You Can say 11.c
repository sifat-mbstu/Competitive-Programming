#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000];
    int sum,sum1,i,length,subs;
    while (gets(str))
    {
        if(str[0]==48 && str[1]=='\0')
        {
            break;
        }
        sum=sum1=0;
        length = strlen(str);
        for(i=0; i<length; i++)
        {
            if(i%2!=0)
            {
                sum=sum+(str[i]-'0');
            }
            else
            {
                sum1=sum1+(str[i]-'0');
            }
        }
        subs=sum-sum1;
        if(subs%11==0)
        {
            printf("%s is a multiple of 11.\n",str);
        }
        else
        {
            printf("%s is not a multiple of 11.\n",str);
        }
    }
    return 0;

}
