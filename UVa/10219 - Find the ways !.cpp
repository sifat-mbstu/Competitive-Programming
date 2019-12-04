///I think this is a Very Good Code

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    //freopen("out.txt", "w", stdout);
    ll a,n,r,i,j,k,multi,a1[1000],a2[1000];
    while(cin >> n >> r)
    {
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));

        if(r == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            if(r > n/2)
            {
                r = n-r;
            }
            j = 0;
            for(i=n; i>n-r; i--,j++)
            {
                a1[j] = i;
                a2[j] = j+1;
            }
            for(i=j-1; i>=0; i--)
            {
                for(k=j-1; k >=0; k--)
                {
                    if((a1[i] % a2[k] ==0) && a2[k] != -1)
                    {
                        a1[i] = a1[i] / a2[k];
                        a2[k] = -1;
                    }
                }
            }
            multi = 1;
            ll sum = 0.0;
            for(i=0; i<j; i++)
            {
                sum += log10(a1[i]);
            }
            ll res = floor(sum)+1 ;
            cout << res << endl;
        }
    }
}
