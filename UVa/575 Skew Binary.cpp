#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[100];
    long int i,num,num1,t,len,sum;
    while(gets(str))
    {
        if(strcmp(str,"0")==0)
        {
            break;
        }
        sum=0;
        len = strlen(str);
        t=0;
        for(i=len-1; i>=0; i--)
        {
            num = str[i] - '0';
            num1 = pow(2,++t) - 1;
            //printf("Num1 = %d t = %d\n",num1,t);
            sum = sum + num * num1;
        }
        printf("%d\n",sum);
    }
}
