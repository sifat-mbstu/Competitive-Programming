#include<bits/stdc++.h>
using namespace std;
int main()
{
    int b, s, Min, num,i,x=0;
    while(cin >> b >> s){
    if(!b && !s) break;
    Min = 100;
    for(i=0; i<b; i++)
    {
        scanf("%d",&num);
        Min = min(Min, num);
    }
    for(i=0; i<s; i++)
    {
        scanf("%d",&num);
    }
    if(b <= s){printf("Case %d: 0\n",++x);}
    else if(b > s){printf("Case %d: %d %d\n",++x, b-s, Min);}
    }
}
