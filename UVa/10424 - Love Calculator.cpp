#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[30],C;
    float Per;
    int num,i,sum,len,sum1,test,Fin,Fin1,New,New1;
    while(gets(str))
    {
        test=1;
        sum=sum1=Fin=Fin1=New=New1=0;
        len=strlen(str);
        for(i=0; i<len; i++)
        {
            if(str[i]<='Z' && str[i]>='A')
            {
                num=str[i]-'A'+1;
                sum=sum+num;
            }
            else if(str[i]<='z' && str[i]>='a')
            {
                num=str[i]-'a'+1;
                sum=sum+num;
            }
            else
            {
                continue;
            }
        }
        sum1=sum;
        sum=0;
        gets(str);
        len=strlen(str);
        for(i=0; i<len; i++)
        {
            if(str[i]<='Z' && str[i]>='A')
            {
                num=str[i]-'A'+1;
                sum=sum+num;
            }
            else if(str[i]<='z' && str[i]>='a')
            {
                num=str[i]-'a'+1;
                sum=sum+num;
            }
        }

        if(sum>9)
        {
            while(sum!=0)
            {
                Fin = Fin + sum%10;
                sum=sum/10;
            }
            sum=Fin;
        }
        if(Fin>9)
        {
            while(Fin!=0)
            {
                New = New + Fin%10;
                Fin=Fin/10;
            }
            sum=New;
        }
        if(sum1>9)
        {
            while(sum1!=0)
            {
                Fin1 = Fin1 + sum1%10;
                sum1=sum1/10;
            }
            sum1=Fin1;
        }
        //printf("Fin1=%d\n",Fin1);
        if(Fin1>9)
        {
            while(Fin1!=0)
            {
                New1 = New1 + Fin1%10;
                Fin1=Fin1/10;
            }
            sum1=New1;
        }
        cout << sum << " " << sum1 << endl;
        if(sum>=sum1)
        {
            printf("%.2f %%\n",float(sum1)/float(sum)*100.0);
        }
        else
        {
            printf("%.2f %\n",float(sum)/float(sum1)*100.0);
        }
    }
    return 0;
}
