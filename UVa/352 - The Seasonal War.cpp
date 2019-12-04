#include<bits/stdc++.h>
using namespace std;
#define FI freopen("input.txt", "r", stdin)
#define FO freopen("output.txt", "w", stdout)
int row,col;
char grid[200][200];
int ara[200][200];
void country(int m, int n)
{
    if(m == row || n == col || n < 0 || m < 0)
    {
        return;
    }
    if (ara[m][n] == 0)
    {
        ara[m][n] = 1;
        if(grid[m][n] == '1')
        {
            country(m+1,n);
            country(m,n+1);
            country(m-1,n);
            country(m,n-1);
            country(m+1,n-1);
            country(m-1,n+1);
            country(m+1,n+1);
            country(m-1,n-1);
        }
    }
}
int main()
{
  //  FI;FO;
    char c;
    int i,j,counts=0, x = 0;
    while(scanf("%d",&row)==1)
    {
        col = row;
        counts = 0;
 //   if(row == 0 ) {break;}
    c = getchar();
    for(i=0;i<row;i++)
    {
        gets(grid[i]);
        //puts(grid[i]);
    }
    memset(ara, 0, sizeof(ara));
    //col = strlen(grid[0]);
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(grid[i][j] == '1' && ara[i][j] == 0)
            {
                counts++;
                country(i,j);
            }
        }
    }
    printf("Image number %d contains %d war eagles.\n",++x, counts);
    }
}
