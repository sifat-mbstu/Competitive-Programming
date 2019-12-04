#include<stdio.h>
#include<string.h>
int main()
{
    char s[50];
    double New,len,multi,times,sum,time[1000],result=0;
    int sec,min,hour,num,i,j,k=0;
    while (gets(s))
    {
        len = strlen(s);
        sec = (s[6] - '0')*10 + (s[7]-'0');
        min = (s[3] - '0')*10 + (s[4]-'0');
        hour = (s[0] - '0')*10 + (s[1]-'0');
        time[k] = (double) sec/3600.0 + (double) min/60.0 + (double) hour;
        if(k>0)
        {
            times=time[k] -time[k-1] ;
        }

        if(len>8)
        {
            New=len-9;

            if(k>0)
            {
                result = result + sum *times;
            }
            sum=0.0,multi=1.0;

            for(i=len-1; i>len-New-1; i--)
            {
                num = s[i] - '0';
                num = num * multi;
                sum = sum + num;
                multi = multi * 10.0;
            }

        }

        else
        {
                printf("%s",s);
            result = result + sum *times;
            printf(" %.2lf km\n",result);
        }
        k++;
    }
    return 0;
}
