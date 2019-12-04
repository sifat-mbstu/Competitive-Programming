#include<stdio.h>
#include<string.h>
int main()
{
    int n,len,num,sum,i,multi;
    char str[100];
    while(gets(str))
    {
        sum=0;
        multi=1;
        len =strlen(str);
        num=str[0]-'0';
        if(num <=9 && num >=0)
        {
            for(i=len-1; i>=0; i--)
            {
                num=str[i]-'0';
                sum=sum+num*multi;
                multi*=10;
            }
            n=sum;
            while(n!=0)
            {
                if(n>=1000)
                {
                    printf("M");
                    n-=1000;
                }
                else if(n>=900)
                {
                    printf("CM");
                    n-=900;
                }
                else if(n>=500)
                {
                    printf("D");
                    n-=500;
                }
                else if(n>=400)
                {
                    printf("CD");
                    n-=400;
                }
                else if(n>=100)
                {
                    printf("C");
                    n-=100;
                }
                else if(n>=90)
                {
                    printf("XC");
                    n-=90;
                }
                else if(n>=50)
                {
                    printf("L");
                    n-=50;
                }
                else if(n>=40)
                {
                    printf("XL");
                    n-=40;
                }
                else if(n>=10)
                {
                    printf("X");
                    n-=10;
                }
                else if(n==9)
                {
                    printf("IX");
                    n-=9;
                }
                else if(n>=5)
                {
                    printf("V");
                    n-=5;
                }
                else if(n==4)
                {
                    printf("IV");
                    n-=4;
                }
                else if(n<4)
                {
                    printf("I");
                    n-=1;
                }
            }
            printf("\n");
        }

        else
        {
            for(i=0; i<len; i++)
            {
                //printf("%d\n",sum);
                if(str[i]=='M')
                {
                    sum+=1000;
                }
                else if(str[i]=='D')
                {
                    sum+=500;
                }
                else if(str[i]=='C')
                {
                    if(i+1 < len && str[i+1]=='M')
                    {
                        sum+=900;
                        i++;
                    }
                    else if(i+1 < len && str[i+1]=='D')
                    {
                        sum+=400;
                        i++;
                    }
                    else
                    {
                        sum+=100;
                    }
                }
                else if(str[i]=='L')
                {
                    sum+=50;
                }
                else if(str[i]=='X')
                {
                    if(i+1 < len && str[i+1]=='C')
                    {
                        sum+=90;
                        i++;
                    }
                    else if(i+1 < len && str[i+1]=='L')
                    {
                        sum+=40;
                        i++;
                    }
                    else
                    {
                        sum+=10;
                    }
                }
                else if(str[i]=='V')
                {
                    sum+=5;
                }
                else if(str[i]=='I')
                {
                    if(i+1 < len && str[i+1]=='X')
                    {
                        sum+=9;
                        i++;
                    }
                    else if(i+1 < len && str[i+1]=='V')
                    {
                        sum+=4;
                        i++;
                    }

                    else
                    {
                        sum++;
                    }
                }
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
