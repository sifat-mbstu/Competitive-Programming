#include<bits/stdc++.h>
using namespace std;
int row,col;
int Mat[200][200];
int ara[200][200];
int cnt;
void equi(int m, int n, int i)
{
   // printf("m = %d n = %d i = %d cnt = %d\n",m,n,i,cnt);
    if(m == row+1 || n == col+1 || n < 1 || m < 1)
    {
       // printf("END_____END\n");
        return ;
    }
    if (ara[m][n] == 0)
    {
        if(Mat[m][n] == i)
        {
             ara[m][n] = 1;
            cnt++;
            equi(m+1,n, i);
            equi(m,n+1, i);
            equi(m-1,n, i);
            equi(m,n-1, i);
        }
    }
}
int main()
{
  //  freopen("output.txt", "w", stdout);
    char c;
    int i,j,counts=0;
    while(scanf("%d",&row)==1)
    {
        counts=0;
        memset(Mat, 0, sizeof(Mat));
            memset(ara, 0, sizeof(ara));
        col = row;
        counts = 0;
    if(row == 0 ) {break;}
    for(i=1;i<=row-1;i++)
    {
        int x,y;
        while(cin >> x >> y){
        Mat[x][y] = i;
        c = getchar();
        if(c == '\n') break;
        }

    }
    for(i=1;i<=row;i++)
    {
        for(j=1; j<=row; j++){
        if(Mat[i][j] == 0){
            Mat[i][j]= row;
        }
        //cout << Mat[i][j] << " ";
        }
    //cout << endl;
    }

    //col = strlen(Mat[0]);
    bool good = 1;
    for(i=1;i<=row;i++)
    {
        for(j=1;j<=col;j++)
        {
            for(int ii = 1; ii <= row; ii++){
            if(Mat[i][j] == ii && ara[i][j] == 0)
            {
                counts++;
                cnt = 0;
                equi(i,j,ii);
                //cout <<"so we get ..cnt= "<< cnt << endl;
                if(cnt != row) {good = false; break;}
            }
            }
        }
        if(!good) break;
    }
    if(good) cout << "good\n";
    else cout << "wrong\n";
    }
}
