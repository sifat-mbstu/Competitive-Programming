#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
struct matrix
{
    ll row,col;
    ll v[4][4];
};
ll dn;
void ppr(matrix mat)
{
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            printf("%lld = ",mat.v[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}
matrix multiply(matrix x, matrix y)
{
    matrix r;
    r.row = x.row;
    r.col = y.col;
    for(int i=0; i<r.row; i++)
    {
        for(int j=0; j<r.col; j++)
        {
            ll ans = 0;
            for(int k=0; k<x.col; k++)
            {
                ans += x.v[i][k] * y.v[k][j];
            }
            r.v[i][j] = ans;
        }
    }
    return r;
}
matrix power(matrix mat, ll p)
{
    matrix res;
    res.col = res.row = dn;
    for(int i=0; i<dn; i++)
    {
        for(int j=0; j<dn; j++)
        {
            res.v[i][j] = 0;
        }
    }
    for(int i=0; i<dn; i++)
        res.v[i][i] = 1;

    for(ll i=p; i>0; i/=2)
    {
        if(i%2==1) res = multiply(res,mat);
//        ppr(res);
        mat = multiply(mat,mat);
    }
    return res;
}
int main()
{
    int TC,idx=0;
    scanf("%d",&TC);
    while(TC--){
    ll apb,ab, n;
    scanf("%llu %llu %llu",&apb, &ab, &n);
    ll ans;
    if(n<=1)
    {
        if(n==0) ans = 2;
        if(n==1) ans = apb;
    }
    else
    {
        matrix mat;
        mat.row = mat.col = dn = 2;
        mat.v[0][0] = apb;
        mat.v[0][1] = -ab;
        mat.v[1][0] = 1;
        mat.v[1][1] = 0;

//        ppr(mat);
        matrix now = power(mat,n-1);
        ans = now.v[0][0] * (apb) + now.v[0][1] * 2;
    }
    printf("Case %d: %llu\n",++idx,ans);
    }
}
