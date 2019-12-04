#include<bits/stdc++.h>
using namespace std;
# define max 10100
int ara_v[max];
int main()
{
    int go,come,vol_come,i;
    while(scanf("%d %d",&go,&come)==2)
    {
        memset(ara_v,0,sizeof(ara_v));
        for(i=0;i<come;i++)
        {
            scanf("%d",&vol_come);
            ara_v[vol_come-1] = 1;
        }
        if(come==go){printf("*\n");}
        else{
        for(i=0;i<go;i++)
        {
            if(ara_v[i] == 0){printf("%d ",i+1);}
        }
        printf("\n");
    }
    }
}
