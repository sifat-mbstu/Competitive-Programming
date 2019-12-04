#include<stdio.h>
int main()
{
    char c;
    int first,second,res1,res2,i;
    scanf("%d",&i);
    while(i--)
    {
        scanf("%d %c %d",&first,&c, &second);

        if((first==12 || first==6) && second==0){res1=first;res2=second;}
        else if(second==0){res1=12-first;res2=second;}
        else {res1=12-first-1;res2=60-second;}
        if(res1==0){res1=12;}
        else if(res1<0){res1=12+res1;}
        printf("%02d%c%02d\n",res1,c,res2);
    }
    return 0;
}
