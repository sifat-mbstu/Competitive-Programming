#include<bits/stdc++.h>
using namespace std;
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)

#define ll long long
struct matrix
{
    ll row,col;
    ll v[5][5];
};
ll mod;
ll dn;
matrix multiply(matrix x, matrix y)
{
    assert(x.col == y.row);
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
    assert(p >= 1);
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
    for(ll i = p; i>0; i/=2)
    {
        if(i%2) res = multiply(res,mat);
        mat = multiply(mat,mat);
    }
    return res;
}


int main()
{
//    FO;
    ll TC,idx=0;
    scanf("%lld",&TC);
    while(TC--)
    {
        ll a,b,n,m;
        scanf("%lld %lld %lld %lld",&a,&b,&n,&m);

        mod = 1;
        for(ll i=0; i<m; i++)
        {
            mod *= 10;
        }

        matrix mat;
        mat.row = mat.col = dn = 2;
        mat.v[0][0] = mat.v[0][1] = mat.v[1][0] = 1;
        mat.v[1][1] = 0;
        if(n<3)
        {
            a %= mod;
            b %= mod;
            if(n==0) printf("Case %lld: %lld\n",++idx,a);
            if(n==1) printf("Case %lld: %lld\n",++idx,b);
            if(n==2) printf("Case %lld: %lld\n",++idx,(a+b)%mod);
            continue;
        }
        matrix now = power(mat,n);
        for(int ii=0; ii<2; ii++)
        {
            for(int jj=0; jj<2; jj++)
            {
                cout << now.v[ii][jj] << " = ";
            }
            cout << endl;
        }
        ll ans = ((now.v[0][0]%mod) * (a%mod) + (now.v[0][1]%mod) * (b%mod))%mod;
        printf("Case %lld: %lld\n",++idx,ans);
//        cout << mod << endl;

    }
    return 0;
}
