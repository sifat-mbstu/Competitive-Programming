///Time limit
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool perfect(ll n)
{
    long long sum,a,test,i;
    long long range;
    sum=0;
    range = sqrt(n);
    for(a=1; a<=range; a++)
    {
        if((n%a)==0)
        {
            sum=sum+a;
            if((n/a)!=a && a!=1)
            {
                sum=sum+n/a;
            }
        }
    }
    if(sum==n)
    {
        return 1;
    }
    return 0;
}
int main()
{
    ll n, a, b, x,i,res;
    while(cin >> n)
    {
        for(i=0; i<n; i++)
        {
            if(i==0) cin >> x;
            else
            {
                scanf(",%d",&x);
            }
            a = pow(2, x-1);
            b = pow(2, x);
            res = a * (b-1);
            //cout << res << endl;
            bool fin = perfect(res);
            if(fin) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
