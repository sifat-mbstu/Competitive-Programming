///Change Whole Logic
#include<bits/stdc++.h>
using namespace std;
#define FI freopen("input.txt", "r", stdin)
#define FO freopen("output.txt", "w", stdout)
int a[3][3], b[3][3], t;
void print()
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("a[%d][%d] = %d  ",i,j,a[i][j]);
            printf("b[%d][%d] = %d\n",i,j,b[i][j]);
        }
    }
    printf("t = %d\n",t);
    cout <<endl <<endl;
}

int main()
{
    FI;FO;
    int  i, j, TC, fi, fj,x,gi,gj;
    cin >> TC;
    for(x = 1; x <= TC; x++){
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            cin >> a[i][j];
        }
    }

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            cin >> b[i][j];
        }
    }
    //if(a[1][0] == b[1][0]) cout << "WHAT THE HELL !!!!\n ";
    //print();

    t = 0;
    for(i = 0; i < 4; i++)
    {
        cin >> a[i]
    }

    if(t == 2){
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            if(a[0][1] == b[i][j])
            {
                gi = !i;
                gj = !j;
                if(t == 2 && (a[1][0] == b[gi][gj])) {t = 4; break;}
            }
        }
    }
    }
    a[0][2] = a[1][0];
    b[0][2] = b[1][0];
    a[0][3] = a[1][1];
    b[0][3] = b[1][1];
    sort(a[0],a[0]+4);
    sort(b[0],b[0]+4);

    for(i = 0; i < 4; i++)
    {
        if(b[0][i] != a[0][i]){t = 0; break;}
    }

    //print();
    //cout << t << endl;
    if(t == 4){ if((a[1][1] == b[!fi][!fj]) && (a[1][0] == b[!gi][!gj]) ){ ;}
    else if(a[1][1] == a[1][0]){;}
        else {t = 0;}}
    if(t == 4){ printf("Case #%d: POSSIBLE\n",x);}
    else { printf("Case #%d: IMPOSSIBLE\n",x);}
    }
}
