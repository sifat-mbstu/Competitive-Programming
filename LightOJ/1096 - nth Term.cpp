#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct matrix
{
    ll row,col;
    ll v[6][6];
};
ll dn, mod = 10007;

matrix multiply(matrix x, matrix y)
{
    matrix r;
    r.row = x.row;
    r.col = y.col;
    for(int i=0; i<r.row; i++)
    {
        for(int j=0; j<r.col; j++)
        {
            ll sum = 0;
            for(int k=0; k<x.col; k++)
            {
                sum += x.v[i][k] * y.v[k][j];
                sum %= mod;
            }
            r.v[i][j] = sum;
        }
    }
    return r;
}
matrix power(matrix mat, ll p)
{
    matrix res;
    res.row = res.col = dn;
    for(int i=0; i<dn; i++)
    {
        for(int j=0; j<dn; j++)
        {
            res.v[i][j] = 0;
        }
    }
    for(int i=0; i<dn; i++) res.v[i][i] = 1;
    for(ll i=p; i>0; i/=2)
    {
        if(i%2) res = multiply(res,mat);
        mat = multiply(mat,mat);
    }
    return res;
}
int main()
{
    ll TC, idx = 0;
    scanf("%lld",&TC);
    while(TC--)
    {
        ll n,a,b,c;
        scanf("%lld %lld %lld %lld",&n,&a,&b,&c);

        if(n<=2) printf("Case %lld: 0\n",++idx);
        else
        {
            matrix mat;
            mat.row = mat.col = dn = 4;
            for(int i=0; i<dn; i++)
            {
                for(int j=0; j<dn; j++)
                {
                    mat.v[i][j] = 0;
                }
            }
            a %= mod;
            b %= mod;
            c %= mod;

            mat.v[0][0] = a;
            mat.v[0][2] = b;
            mat.v[0][3] = 1;
            mat.v[1][0] = 1;
            mat.v[2][1] = 1;
            mat.v[3][3] = 1;
            ppr(mat);
            matrix now = power(mat,n-2);
            ll ans = (now.v[0][3]*c)%mod;
            printf("Case %lld: %lld\n",++idx,ans);
        }
    }
}
