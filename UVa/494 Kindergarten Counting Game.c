#include<stdio.h>
#include<string.h>
int main()
    {
        char str[3000];
        int num,len,i,test,count;
        while(gets(str))
    {
        count = test = 0;
        len = strlen(str);
        for(i=0;i<len;i++)
        {
            num = str[i] ;
            if((num>=97 && num<=122) || (num>=65 && num<=90))
        {
            test =1;
        }
        else { if(test){count++;test=0;} }
        }
        if(test){count++;}
        printf("%d\n",count);
    }
        return 0;
}
