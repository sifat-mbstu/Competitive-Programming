#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i[5],j[5],t,x;
    while(scanf("%d%d%d%d%d",&i[0],&i[1],&i[2],&i[3],&i[4])==5)
    {
        t=1;
/*          scanf("%d",&i_1);
            scanf("%d",&i_2);
            scanf("%d",&i_3);
            scanf("%d",&i_4);
            scanf("%d",&i_5);

            scanf("%d",&j_1);
            scanf("%d",&j_2);
            scanf("%d",&j_3);
            scanf("%d",&j_4);
            scanf("%d",&j_5);
*/
        for(x=0;x<5;x++)
            {
                scanf("%d",&j[x]);
                if(i[x]==j[x]){t=0;}
            }

        /**if(i_1==j_1){t=0;}
        else if(i_2==j_2){t=0;}
        else if(i_3==j_3){t=0;}
        else if(i_4==j_4){t=0;}
        else if(i_5==j_5){t=0;}
        else{t=1;}
*/
        if(t){printf("Y\n");}
        else{printf("N\n");}
    }
    return 0;
}
