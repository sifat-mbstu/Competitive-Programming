#include<stdio.h>
int main()
{
    unsigned long long f,N=91;
    while(scanf("%llu",&f)==1 && f!=0)
    {
        if(f<=100){printf("f91(%llu) = %llu\n",f,N);}
        else{printf("f91(%llu) = %llu\n",f,f-10);}
    }
    return 0;
}
