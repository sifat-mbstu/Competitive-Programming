#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[25],C;
    int i,j,num,sum;
    scanf("%d",&j);
    C=getchar();
    while(j--)
    {
        sum=0;
        gets(str);
        for(i=0; i<19; i++)
        {
            if(i==0 || i==2 || i==5 || i==7 || i==10 || i==12 || i==15 || i==17)
            {
                num = (str[i] - '0')*2;
                // printf("%d",num);
                if(num>=10)
                {
                    sum = sum + num%10;
                    num = num /10;
                    sum = sum + num;
                }
                else
                {
                    sum = sum + num;
                }
            }
            else
            {
                if(str[i]!=' ')
                {
                    num = str[i] - '0';
                    sum = sum+num;
                }
            }
        }
        //printf("%d\n",sum);
        if((sum%10)==0)
        {
            printf("Valid\n");
        }
        else
        {
            printf("Invalid\n");
        }
    }
    return 0;
}
