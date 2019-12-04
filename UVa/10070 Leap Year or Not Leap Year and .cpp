#include<bits/stdc++.h>
#define Max 100000
char str[Max];
using namespace std;
int main()
{
    long long int len,n,sign,sum,sum_ele,i,num,test=0;;
    int t,leap,three,four,five,eleven,hundred,four_hund;
    while(gets(str))
    {
        if(test!=0)
        {
            printf("\n");
        }
        test++;
        t=1;
        leap=sum=sum_ele=three=four=five=eleven=hundred=four_hund=0;
        len = strlen(str);
        if(len>1)
        {
            n = str[len-1]+str[len-2]-'0'-'0';
        }
        else
        {
            n = str[len-1]-'0';
        }
        if(str[len-1]=='5' || str[len-1]=='0')
        {
            five=1;
            sign=1;
            sum =sum_ele=0;
            for(i=0; i<len; i++)
            {
                num = str[i] - '0';
                sum = sum + num;
                sum_ele=sum_ele + num*(sign);
                sign = sign *(-1);
            }
            if((sum%3)==0)
            {
                three=1;
            }
            if((sum_ele%11)==0)
            {
                eleven=1;
            }
        }
        if(n%4==0)
        {
            four =1;
            if(str[len-1]=='0' && str[len-2]=='0')
            {
                hundred =1;
                for(i=len-3; i>=0; i--)
                {
                    if(str[i-1]!='0')
                    {
                        if((i-1)<0)
                        {
                            num = str[i] - '0';
                        }
                        else
                        {
                            num = (str[i] - '0') + 10 *(str[i-1]-'0');
                        }
                        break;
                    }
                    //  printf("%c",str[i]);
                }
                //       printf("num == %lld\n",num);
                if(num%4==0)
                {
                    four_hund=1;
                }
            }
        }

        if(four_hund==1|| (hundred!=1 && four==1) )
        {
            t=0;
            leap=1;
            printf("This is leap year.\n");
        }
        if(three==1 && five==1)
        {
            t=0;
            printf("This is huluculu festival year.\n");
        }
        if(eleven==1 && five==1 && leap==1)
        {
            t=0;
            printf("This is bulukulu festival year.\n");
        }
        if(t)
        {
            printf("This is an ordinary year.\n");
        }
    }
}

