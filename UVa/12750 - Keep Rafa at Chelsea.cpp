#include<stdio.h>
int main()
{
    long long int i,j,n,out,stay,CASE,test_out,test_stay ;

    char c;
    scanf("%lld",&CASE);
    for(j=1;j<=CASE;j++)
    {
    scanf("%lld",&n);
    //scanf("%c",&d);
    test_out = test_stay = out = stay = 0;
    for(i=0;i<n;i++)
    {
        //printf("i = %d\n",i);
        scanf("\n%c",&c);
        //c =getchar();
        if(c =='W'){out=0;stay++;}
        else{out++;stay++;}

        //printf("out = %d\n",out);
        if(test_stay==0){
        if(out==3){test_stay=stay;}
        else{test_out=1;}
        }
    }
    if(test_stay!=0){printf("Case %lld: %d\n",j,test_stay);}
    else if(test_out!=0){printf("Case %lld: Yay! Mighty Rafa persists!\n",j);}
    }
    return 0;
}
