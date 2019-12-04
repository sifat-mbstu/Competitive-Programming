#include<bits/stdc++.h>
using namespace std;

int check_digit(char c)
{
    if(c>= '0' && c<= '9')
    {
        return 1;
    }
    return 0;
}
int main()
{
    char str[120][120];
    int ara[10] ;
    int i, j, Plus, Minus, Total=0,len,Count = 0,k,num;


    while(gets(str[Total]))
    {
        Total++;
    }
    for(i=0; i< Total; i++)
    {
        for(j=0; j< 5; j++)
        {
        ara[j] = 0;
        }
        len = strlen(str[i]);
        if(str[i][len-1] !=63)
        {
            Plus = 0;
            Minus =0;
            k = 0;
            for(j=0; j<len ;j++)
            {
                if(check_digit(str[i][j]))
                {
                    num = str[i][j] - '0';
                    ara[k] = ara[k] * 10 + num;
                }
                else
                {
                    k++;
                    if(str[i][j]=='+'){Plus = 1;}
                    else if(str[i][j]=='-'){Minus =1;}
                }
            }
            //printf("ara = %d %d %d\nPlus = %d\n",ara[0],ara[1],ara[2],Plus);
            if(Plus)
            {
                if((ara[0]+ ara[1])==ara[2])
                {
                    Count++;
                }
            }
            else if(Minus)
            {
                if((ara[0] - ara[1])==ara[2])
                {
                    Count++;
                }
            }
        }
    }
    printf("%d\n",Count);
}
