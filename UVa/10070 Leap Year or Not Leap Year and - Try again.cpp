#include<bits/stdc++.h>
#define Max 100000
char str[Max];
using namespace std;
int main()
{
    int len,rem,sum,i,rem1,leap =0,hulu=0,bulu=0;

    char str[1060];
    int test =0;
    while(gets(str))
    {

        leap = hulu = bulu=0;
        len = strlen(str);
        rem = 0 ;
        rem1 = 0 ;

        for(i=0; i<len; i++)
        {
            sum = rem * 10 + (str[i]-'0');
            rem = sum % 400;
        }
        if(rem==0){leap = 1;}
        else{
        for(i=0; i<len; i++)
        {
            sum = rem * 10 + (str[i]-'0');
            rem = sum % 4;
        }

        for(i=0; i<len; i++)
        {
            sum = rem1 * 10 + (str[i]-'0');
            rem1 = sum % 100;
        }
        if(rem==0 && rem1!=0) {leap =1;}
        }
        rem = 0 ;
        for(i=0; i<len; i++)
        {
            sum = rem * 10 + (str[i]-'0');
            rem = sum % 15;
        }
        if(rem==0){hulu = 1;}

        rem = 0 ;
        if(leap==1){
        for(i=0; i<len; i++)
        {
            sum = rem * 10 + (str[i]-'0');
            //printf("bulu = %d\n",rem);
            rem = sum % 55;
        }
        if(rem==0){bulu = 1;}
        }
        if(test!=0)
        {
            printf("\n");
        }
        if(leap==1) printf("This is leap year.\n");
        if(hulu==1) printf("This is huluculu festival year.\n");
        if(bulu==1) printf("This is bulukulu festival year.\n");
        if(leap ==0 && hulu==0 && bulu==0) printf("This is an ordinary year.\n");
        test++;
    }
}
