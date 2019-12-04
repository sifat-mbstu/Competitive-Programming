#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("a.txt","w",stdout);*/
    int TC,i,j,k,n,ara[100],D,X;
    char str[100][100], sub[100];
    scanf("%d",&TC);
    for(j=1;j<=TC;j++)
    {
        X = -1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s %d",&str[i], &ara[i]);
        }
        scanf("%d",&D);
        scanf("%s",&sub);
        for(i=0;i<n;i++)
        {
            if(strcmp(str[i],sub)==0){X = i; break;}
        }
        if(X==-1 || ((D+5) < ara[X])) { printf("Case %d: Do your own homework!\n",j);}
        else if(D >= ara[X]){ printf("Case %d: Yesss\n",j);}
        else if(D+5 >= ara[X]){ printf("Case %d: Late\n",j);}
    }
}
