#include<bits/stdc++.h>
using namespace std;
int main()
{
    int D,O,H,P,hunter;

    while(scanf("%d %d %d",&P,&H,&O)==3){
    hunter = 0;
    if(H >= O){ hunter = 1;}
    else
        {
            D = abs(O - H);
            if(D<P){hunter = 1;}
        }
    if(hunter){ printf("Hunters win!\n");}
    else { printf("Props win!\n");}
}
}
