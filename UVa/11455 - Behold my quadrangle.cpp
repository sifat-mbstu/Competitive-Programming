#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[5],maxi,i,N;
    scanf("%d",&N);
    while (N--)
    {
        scanf("%d %d %d %d",&ara[0],&ara[1],&ara[2],&ara[3]);
        sort (ara,ara+4);

        //printf("%llu %llu %llu%llu",ara[0],ara[1],ara[2],ara[3]);

        if (ara[0]==ara[1] && ara[1]==ara[2] && ara[2]==ara[3])
        {
            printf("square\n");
        }
        else if (ara[0]==ara[1] && ara[2]==ara[3])
        {
                printf("rectangle\n");
        }
        else if(ara[3]<(ara[0]+ara[1]+ara[2]))
        {
            printf("quadrangle\n");
        }
        else
        {
            printf("banana\n");
        }
    }
    return 0;
}
