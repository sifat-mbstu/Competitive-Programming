#include<bits/stdc++.h>
using namespace std;
int main()
{
    int H1, H2, M1, M2, H3, H4, M3, M4, TC;
    bool Mrs;
    cin >> TC;
    for(int i = 1; i <= TC; i++){
    scanf("%d:%d",&H1,&M1);
    scanf("%d:%d",&H2,&M2);
    scanf("%d:%d",&H3,&M3);
    scanf("%d:%d",&H4,&M4);
    Mrs = 0;
    if(H3 >= H1 && H3 <= H2)
    {
        if(H3 == H1 && H3 == H2){if((M3 >= M1)&&(M3 <= M2)){Mrs = 1;}}
        else if(H3 == H1){ if(M3 >= M1){Mrs = 1;}}
        else if (H3 == H2){ if(M3 <= M2){ Mrs = 1;}}
        else{Mrs = 1;}
    }
    if(H4 >= H1 && H4 <= H2)
    {
        if(H4 == H1 && H4 == H2){if((M4 >= M1)&&(M4 <= M2)){Mrs = 1;}}
        else if(H4 == H1){ if(M4 >= M1){Mrs = 1;}}
        else if (H4 == H2){ if(M4 <= M2){ Mrs = 1;}}
        else{Mrs = 1;}
    }
    if((H3 <= H1) && (H4 >= H2)){
        if(H4 == H2){ if(M4 >= M2){Mrs = 1;}}
        else if (H3 == H1){ if(M3 <= M1){ Mrs = 1;}}
        else{Mrs = 1;}
    }
    if(Mrs){ printf("Case %d: Mrs Meeting\n",i);}
    else{ printf("Case %d: Hits Meeting\n",i);}
    }
}
