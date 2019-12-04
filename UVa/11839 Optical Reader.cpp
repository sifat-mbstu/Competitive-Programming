#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a, bl,i;
    char ch;
    while(cin >> n){
    if(!n) break;
    for(i=0; i<n; i++)
    {
        bl = 0;
        for(int j=0; j<5; j++)
        {
            scanf("%d",&a);
            if(a >= 0 && a <= 127){bl++; ch = 'A' + j;}
        }
        if(bl != 1){ch = '*';}
        printf("%c\n",ch);
    }
    }
}
