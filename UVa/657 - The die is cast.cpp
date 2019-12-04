#include<bits/stdc++.h>
using namespace std;
int row,col;
vector<int> res;
vector<int> :: iterator it;
char grid[200][200];
int ara[200][200];
int x[200][200];
int cnt;
void x_check(int m, int n)
{
    if( m == row || n == col || n < 0 || m < 0)
    {
        return;
    }
    if(x[m][n] == 0 && grid[m][n] == 'X' ){
            x[m][n] = 1;
            ara[m][n] = 1;
          if(grid[m][n] == 'X' )
    {
            x_check(m+1,n);
            x_check(m,n+1);
            x_check(m-1,n);
            x_check(m,n-1);
    }
    grid[m][n] = '*';
}
}
void country(int m, int n)
{
    if(m == row || n == col || n < 0 || m < 0)
    {
        return;
    }
    if (ara[m][n] == 0)
    {
        ara[m][n] = 1;
        if(grid[m][n] == 'X' && x[m][n] == 0)
        {
            cnt++;
            //printf("cnt = %d m = %d n = %d x[m][n] = %d\n",cnt,m,n,x[m][n]);
            x_check(m,n);
        }
         if(grid[m][n] == '*')
        {
            country(m+1,n);
            country(m,n+1);
            country(m-1,n);
            country(m,n-1);
        }
    }
}
int main()
{
    char c;
    int i,j,counts=0,TC = 0;
    while(scanf("%d %d",&col,&row)==2){
        counts = 0;
    if(!row  && !col ) {break;}
    c = getchar();
    for(i=0;i<row;i++)
    {
        gets(grid[i]);
        //puts(grid[i]);
    }
    memset(ara, 0, sizeof(ara));
    memset(x, 0, sizeof(x));
    res.clear();
    //col = strlen(grid[0]);
    for(i=0;i<row;i++)
    {

        for(j=0;j<col;j++)
        {
            if((grid[i][j] == '*' && ara[i][j] == 0) || (grid[i][j] == 'X' && x[i][j] == 0))
            {
                counts++;
                cnt = 0;
                country(i,j);
                //cout << cnt << endl;
                if(cnt > 0)res.push_back(cnt);
            }
        }
      //  cout << cnt << endl;
    }
    sort(res.begin(), res.end());
    //if(TC >0) cout << endl;
    printf("Throw %d\n", ++TC);
    for(it = res.begin(); it != res.end(); it++){
        if(it != res.begin()) cout << " ";
        cout<<(*it) ;
    }
    cout << endl << endl;
    }
    //printf("%d\n",counts);
}
/*
SAMPLE:

30 15
..............................
..............................
...............*..............
...*****......****............
...X****.....**X***...........
...*****....***X**............
...***X*.....****.............
...*****.......*..............
..............................
........***........******.....
.......**X****.....*X**X*.....
......*******......******.....
.....****X**.......*X**X*.....
........***........******.....
..............................

*/
