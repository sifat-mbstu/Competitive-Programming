#include<bits/stdc++.h>
using namespace std;
#define mx 110
string A,B;
int len1,len2;
int DP[mx][mx];
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)

int LCS(int i,int j)
{
    if(i==len1 || j==len2) return 0;
    if(DP[i][j]!=-1) return DP[i][j];

    int res=0;
    if(A[i]==B[j])
        res=1+LCS(i+1,j+1);
    else
    {
        int val1 = LCS(i+1,j);
        int val2 = LCS(i,j+1);
        res = max(val1,val2);
    }
    DP[i][j]=res;
    return DP[i][j];
}
int main()
{
//    FO;
    int TC=0;
    while(getline(cin,A)){
    if(A=="#")break;
    memset(DP,-1,sizeof(DP));
    getline(cin,B);
//    cout << A << endl;
//    cout << B << endl;
    len1=A.size();
    len2=B.size();
    printf("Case #%d: you can visit at most %d cities.\n",++TC,LCS(0,0));
    }
    return 0;

}
