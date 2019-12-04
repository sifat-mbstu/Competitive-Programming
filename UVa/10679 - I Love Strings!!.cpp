#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[100100],sub[100100],gen[100100],TC;
    int n,k,t,i,j,len,len1,x,y;
    scanf("%d",&TC);
    while(TC--){
    scanf("%s %d",&s,&n);
    len = strlen(s);
    for(i=1;i<=n;i++)
    {
        y = 0;
        scanf("%s",&sub);
        len1 = strlen(sub);
        x =0;
        for(j=0;j<=(len - (len1-1));j++)
        {
            x = j;
            for(k=0;k<len1;k++)
            {
                gen[k] = s[x];
                x++;
            }
            gen[k] = '\0';
            if(strcmp(gen,sub)==0){ y = 1; break;}
        }
        if(y){printf("y\n");}
        else{printf("n\n");}
    }
    }
}
