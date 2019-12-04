#include<bits/stdc++.h>
using namespace std;
int main()
{
    float a,b,div,c,subs,sum;
    int N;
    scanf("%d",&N);
    while(N--){
    scanf("%f %f %f",&a,&b,&c);
    subs = a + a - b;
    sum = a+b;
    div = subs / sum;
    subs = div * c;
    subs = int(subs);
    if(subs<=0){printf("0\n");}
    else{printf("%.0f\n",subs);}
    }
    return 0;
}
