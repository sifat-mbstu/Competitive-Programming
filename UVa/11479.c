#include<stdio.h>
int main()
{
    unsigned long long int i,a,b,c;
    int test,j;
    scanf("%d",&test);
    for(j=1;j<=test;j++){
        scanf("%llu%llu%llu",&a,&b,&c);
        if( (a>=(b+c)) || (b>=(a+c)) || (c>=(a+b)) ||a==0 || b==0 ||c==0 ){printf("Case %d: Invalid\n",j);}
        else if(a==b && b==c){printf("Case %d: Equilateral\n",j);}
        else if(a==b || b==c || a==c){printf("Case %d: Isosceles\n",j);}
        else {printf("Case %d: Scalene\n",j);}
}
    return 0;
}
