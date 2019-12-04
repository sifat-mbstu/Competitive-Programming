#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long int a,b,n;
    scanf("%llu",&n);
    while(n--)
    {
        scanf("%llu %llu",&a,&b);
        if(a<b || ((a-b)%2)!=0 ){printf("impossible\n");}
        else{printf("%llu %llu\n",(a+b)/2,(a-b)/2);}
    }
}
