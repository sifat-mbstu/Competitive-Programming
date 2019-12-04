#include<bits/stdc++.h>
using namespace std;
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
        if(grid[m][n] == '@')
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
    char c;
    int i,j,counts=0;
    while(scanf("%d %d",&row,&col)==2)
    {
        counts = 0;
    if(row == 0 ) {break;}
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
            if(grid[i][j] == '@' && ara[i][j] == 0)
            {
                counts++;
                country(i,j);
            }
        }
    }
    printf("%d\n",counts);
    }
}
