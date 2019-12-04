#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[100];
    int a[100], i, len,j,cnt,TC,k;
    cin >> TC;
    getchar();
    for(k=1;k<=TC;k++){
    gets(s);
    len = strlen(s);
    memset(a,0,sizeof(a));
    cnt = 0;
    for(i=0; i<len; i++)
    {
        if(s[i] == 'D'){
            a[i] = 1;
        }
        else if(s[i] == 'B'){
            a[i] = 1;
            if(i-1 >= 0){ a[i-1] = 1;}
            if(i-2 >= 0){ a[i-2] = 1;}
          }
        else if(s[i] == 'S')
        {
            a[i] = 1;
            if(i-1 >=0) {a[i-1] = 1;}
            if(i+1 < len) {a[i+1] = 1;}
        }
    }
    for(i=0;i<len;i++)
    {
        if(a[i] == 0) {cnt++;}
    }
    printf("Case %d: %d\n",k,cnt);
    }
}
