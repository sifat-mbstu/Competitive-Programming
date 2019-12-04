///accepted
#include<bits/stdc++.h>
using namespace std;
string str[105];
int n, m;
string check(int row, int col)
{
    int cnt = 0;
    string s;
    if((row > 0 && col > 0) && (str[row-1][col -1] == '*')) { cnt++; }
    if((row < n-1 && col < m-1) && (str[row+1][col+1] == '*')) { cnt++; }
    if((row > 0 && col < m-1) && (str[row-1][col+1] == '*')) { cnt++; }
    if((row < n-1 && col > 0) && (str[row+1][col-1] == '*')) { cnt++; }
    if((row > 0 ) && (str[row-1][col] == '*')) { cnt++; }
    if((row < n-1 ) && (str[row+1][col] == '*')) { cnt++; }
    if((col > 0) && (str[row][col-1] == '*')) { cnt++; }
    if((col < m-1 ) && (str[row][col+1] == '*')) { cnt++; }
    s.push_back(cnt+'0');
    return s;
}
int main()
{
    int i,j, x = 0;
    while(cin >> n >> m){
    if(!n && !m) break;
    for(i=0; i<n; i++) cin >> str[i];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(str[i][j] == '.')
            {
                str[i].replace(j,1,check(i,j));
            }
        }
    }
    if(x != 0){cout << endl;}
    printf("Field #%d:\n",++x);
    for(i=0; i<n; i++)
    {
        cout << str[i] << endl;
    }
    }
}
