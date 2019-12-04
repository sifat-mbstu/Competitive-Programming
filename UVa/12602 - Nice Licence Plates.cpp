#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[100],c;
    int num,num1,res,test;
    scanf("%d",&test);
    c=getchar();
    while(test--)
    {
        gets(str);
        num = (str[0]-'A')*26*26 + (str[1]-'A')*26 + (str[2]-'A');
        num1 = (str[7]-'0') + (str[6]-'0')*10 + (str[5]-'0')*100+ (str[4]-'0')*1000;

        res=abs(num-num1);
        //printf("%d",res);
        if(res<=100)
        {
            printf("nice\n");
        }
        else
        {
            printf("not nice\n");
        }
    }
    return 0;
}
