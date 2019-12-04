#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,l,c,d,p,nl,np,tot_drink,tot_slices,mini,result,x,y,z;
    while(scanf("%d %d %d %d %d %d %d %d",&n,&k,&l,&c,&d,&p,&nl,&np)==8)
    {
    tot_drink=k*l;
    tot_slices=c*d;
    x=tot_drink/nl;
    y=tot_slices;
    z=p/np;
    mini=min(x,y);
    mini=min(mini,z);
    //printf("%d\n",mini);
    result=mini/n;
    printf("%d\n",result);
    }
    return 0;
}

