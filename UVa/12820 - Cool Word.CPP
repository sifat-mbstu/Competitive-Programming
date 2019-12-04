#include<bits/stdc++.h>
using namespace std;
int main()
{
    int F,i,a[220],com, res,TC,x,n;
    char str[20000],c;
    F = 0 ;
    while(scanf("%d",&TC)==1){
    int res = 0;
    c = getchar();
    while(TC--){
    x = com = 0;
    gets(str);
    //puts(str);
    memset(a, 0, sizeof(a));
    int len = strlen(str);
    for(i=0; i<len ; i++)
    {
        n = str[i] - 'a';
        a[n]++;
    }
    for(i=0;i < 26; i++)
    {
        if(a[i]> 0){x++;}
        if(x == 2){break;}
    }
    sort(a,a+26);
    for(i=0; i<26; i++)
    {
        if(a[i] > 0)
        {
            if(a[i] == a[i+1]){ com = 1; break;}
        }
    }
    if(com == 0 && x==2){ res++;}
    //printf("res = %d\n",res);
    }
    printf("Case %d: %d\n",++F,res);
    }
}
