#include<bits/stdc++.h>
using namespace std;
int main()
{
    char phn[1010][20],mem[20];
    int n,i,j,k,len1,len,a[1010],cnt=0,TC,x;
    scanf("%d",&TC);
    for(x=1; x<= TC; x++){
    k=cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",&phn[i]);
    }
    scanf("%s",&mem);
    len = strlen(mem);
    for(i=0; i<n; i++)
    {
        len1= strlen(phn[i]);
        if(strcmp(phn[i],mem)==0)
        {
            a[k] = i;
            k++;
        }
        else if(len1 == len){
        for(j=0; j<= len; j++)
        {
            if(phn[i][j] != mem[j])
            {
                cnt++;
                if(cnt ==2){ break;}
            }
        }
        if(cnt<= 1){a[k] = i; k++;}
        cnt = 0;
        }
    }
    printf("Case %d:\n",x);
    for(i=0; i<k; i++)
    {
                     printf("%s\n",phn[a[i]]);
    }
    /*if(k==0){
        for(i=0;i<n;i++)
        {
            len1 = strlen(phn[i]);
            if(len == len1) printf("%s\n",phn[i]);
        }
    }*/
    }
}
