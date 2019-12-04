///Accepted
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[5], b[5][5], i, j, cnt, TC,x;
    cin >> TC;
    for(x = 1; x <= TC; x++){
    for(i = 0; i < 4; i++)
    {
        cin >> a[i];
    }
    for(i = 0; i < 4; i++)
    {
        cin >> b[0][i];
    }
    b[1][1] = b[0][0];
    b[1][3] = b[0][1];
    b[1][0] = b[0][2];
    b[1][2] = b[0][3];

    b[2][3] = b[0][0];
    b[2][2] = b[0][1];
    b[2][1] = b[0][2];
    b[2][0] = b[0][3];

    b[3][2] = b[0][0];
    b[3][0] = b[0][1];
    b[3][3] = b[0][2];
    b[3][1] = b[0][3];

    for(i = 0; i < 4; i++)
    {
        cnt = 0;
        for(j = 0; j < 4; j++)
        {
            if(a[j] == b[i][j])
            {
                cnt++;
            }
        }
        if(cnt == 4)
        {
            break;
        }
    }
    if(cnt == 4){printf("Case #%d: POSSIBLE\n",x);}
    else {printf("Case #%d: IMPOSSIBLE\n",x);}
}
}
