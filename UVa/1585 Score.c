#include<stdio.h>
#include<string.h>
int main()
{
     int num,i,sum,len,test;
     char str[100],c;
     scanf("%d",&test);
     c = getchar();
     while(test--)
     {
        sum=num=0;
        gets(str);
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]=='O'){ num++;}
            else {num = 0;}
            sum = sum + num;
        }
        printf("%d\n",sum);
     }
     return 0;
}
