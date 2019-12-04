#include<stdio.h>
int main()
{
    int grade,a,b,c,d,e,f,g,h,test,min,i;
    scanf("%d",&test);
    for(i=1;i<=test;i++){
            grade=0;
        scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
        if(e==f && f==g){h=e;}
        else{
            if(e>=f){if(f>=g){min=f;}
                    else{min=g;}}
            else{if (e<=g){min=e;}
                    else{min=g;}}
        h=((e+f+g)-min)/2;
       // printf("h=%d\n",h);
        }
        grade=a+b+c+d+h;
       // printf("sum=%d\n",sum);

    if(grade>=90)
        {
            printf("Case %d: A\n", i);
        }
        else if(grade>=80 && grade<90)
        {
            printf("Case %d: B\n", i);
        }
        else if(grade>=70 && grade<80)
        {
            printf("Case %d: C\n", i);
        }
        else if(grade>=60 && grade<70)
        {
            printf("Case %d: D\n", i);
        }
        else if(grade<60)
        {
            printf("Case %d: F\n", i);
        }
}
return 0;
}
