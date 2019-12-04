#include<bits/stdc++.h>
using namespace std;
#define maxi 2000011
int R[maxi], D[maxi];
int main()
{
    int n,i,j,m,zero,Min,Max,dif,Len;
    char str[maxi],c;
    while(cin >> Len){
    if(Len == 0) break;
    c = getchar();
    gets(str);
    m = 0;
    n = 0;
    zero = 0;
    for(i = 0; i < Len; i++)
    {
        if(str[i] == 'Z'){ zero = 1; break;}
        else if(str[i] == 'D'){ D[m] = i;m++;}
        else if(str[i] == 'R'){ R[n] = i; n++;}
    }
    Min = 20000010;
    Max = max(m,n);

    for(i = 0,j =0; i < m && j < n; )
    {
        dif = abs(D[i] - R[j]);
        if(Min > dif) {Min = dif;}
        if(D[i] < R[j] && i < m) {i++;}
        else if(D[i] > R[j] && j < n) {j++;}
        //cout << dif <<endl;
    }
    if(zero) printf("%d\n",0);
    else{printf("%d\n",Min);}
    }
}
