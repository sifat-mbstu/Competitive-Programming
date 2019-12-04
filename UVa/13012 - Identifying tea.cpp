#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[10],cnt,i;
    while(scanf("%d",&n)==1){
    cnt = 0;
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==n){cnt++;}
    }
    printf("%d\n",cnt);
    }
}
