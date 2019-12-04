#include <stdio.h>
int main()
{
    int b,w,t,k,a,N,i,test;
    char ar[10];
    scanf("%d",&test);
    for(k=1;k<=test;k++){
    b=w=t=a=0;
    scanf("%d",&N);
    for(i=0;i<N+1;i++){
        scanf("%c",&ar[i]);
        if(ar[i]=='B'){b++;}
        else if(ar[i]=='W'){w++;}
        else if(ar[i]=='T'){t++;}
        else {a++;}
    }
    a--;
    if(a==N){printf("Case %d: ABANDONED\n",k);}
    else if(b==N-a && (b!=0)){printf("Case %d: BANGLAWASH\n",k);}
    else if(w==N-a && (w!=0)){printf("Case %d: WHITEWASH\n",k);}
    else if(b==w){if(b==0)printf("Case %d: DRAW %d %d\n",k,b,t);
        else{printf("Case %d: DRAW %d %d\n",k,b,w);}}
    else if(b>w) {printf("Case %d: BANGLADESH %d - %d\n",k,b,w);}
    else {printf("Case %d: WWW %d - %d\n",k,w,b);}
}
return 0;
}
