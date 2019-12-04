#include<stdio.h>
int main()
{
    int real,num,orig,i,r,happy,a,sum,test;
    scanf("%d",&test);
    for(i=1; i<=test; i++)
    {
        happy=1;
        scanf("%d",&num);
        orig = num;
        real = num;
        if(num==2 || num==3)
        {
            orig = num * num;
        }
        happy = 1;
            r=0;
        while(num>9)
        {
            r++;
            sum=0;
            while (num!=0)
            {
                a = num % 10;
                num = num / 10;
                sum = sum + a*a;
            }
            num = sum;
            //printf("%d\n",num);
            if(num == orig)
            {
                happy =0 ;
                break;
            }
            else if(sum == 1)
            {
                happy =1 ;
                break;
            }
            else{happy=0;}
        }
        if(num==1 || num==7)
        {
            printf("Case #%d: %d is a Happy number.\n",i,real);
        }
        else
        {
            printf("Case #%d: %d is an Unhappy number.\n",i,real);
        }
    }
    return 0;
}
