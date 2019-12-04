#include<bits/stdc++.h>

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt cout<<"Case "<<cas++<<": "

using namespace std;

bool bt[35];

int main()
{
    int t, cas=1;
    cin>>t;
    while(t--)
    {
        long long i, j, n;
        cin>>n;
        memset(bt, false, sizeof bt);
        for(i=0, j=31;i<32;i++, j--)
            bt[j] = n&(1<<i);
        next_permutation(bt, bt+32);
//        for(i=0;i<32;i++)
//            cout<<bt[i];
//            cout<<endl;
        long long ans=0;
        for(i=0, j=31;i<32;i++, j--)
            ans = ans|(bt[j]<<i);
        csprnt;
        cout<<ans<<endl;
    }
    return 0;
}
