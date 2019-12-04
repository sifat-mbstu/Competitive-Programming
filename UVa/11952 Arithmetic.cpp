#include<bits/stdc++.h>
using namespace std;
string A,B,C,e,g;
vector<int>vv;
int xx[10];
int power(int x,int p)
{
    int ans=1;
    for(int i=1; i<=p; i++)
    {
        ans*=x;
    }
    return ans;
}
bool fun(int x)
{
    int val = 0;

    for(int i=5; i>=0; i--)
    {
        int pp = power(x,i);
        val += (pp*xx[i]);
    }

    if(val==0)return true;
    else return false;
}
int main()
{
    int tt;
    cin>>tt;

    for(int ks=1; ks<=tt; ks++)
    {
        cin >> A >> e >> B >> g >> C;

        memset(xx,0,sizeof(xx));
        vv.clear();

        bool ff = true;

        //cout << A << x << B << y << C << endl;
        //cout << A << " " <<  B << " " << C << endl;
        int sa = A.size();
        int md = 0;
        for(int i=0,k=sa-1; i<sa; i++,k--)
        {
            xx[k] += (A[i]-'0');
            md = max(md,(A[i]-'0'));
            if((A[i]-'0')!=1)
            {
                ff = false;
            }
        }

        int sb = B.size();
        for(int i=0,k=sb-1; i<sb; i++,k--)
        {
            xx[k] += (B[i]-'0');
            md = max(md,(B[i]-'0'));
            if((B[i]-'0')!=1)
            {
                ff = false;
            }
        }

        int sc = C.size();
        for(int i=0,k=sc-1; i<sc; i++,k--)
        {
            xx[k] -= (C[i]-'0');
            md = max(md,(C[i]-'0'));
            if((C[i]-'0')!=1)
            {
                ff = false;
            }
        }

        if(md==0)
        {
            printf("2\n");
            continue;
        }

        int msb=0,mps=-1,lsb=0,lps=-1;

        for(int i=5; i>=0; i--)
        {
            if(xx[i]!=0)
            {
                msb = abs(xx[i]);
                mps = i;
                break;
            }
        }

        for(int i=0; i<=5; i++)
        {
            if(xx[i]!=0)
            {
                lsb = abs(xx[i]);
                lps = i;
                break;
            }
        }

        int nn = msb*lsb;
        int sq = sqrt(nn);

        if(md==1 && ff==true)vv.push_back(1);

        for(int i=2; i<=sq; i++)
        {
            if(nn%i==0)
            {
                if(i>md)vv.push_back(i);
                int ni = nn/i;
                if(i!=ni && ni!=1)
                {
                    if(ni>md)vv.push_back(ni);
                }
            }
        }
        if(nn>md && nn!=1)vv.push_back(nn);

        if(mps==-1 || lps==-1)
        {
            for(int i=2; i<=10; i++)
            {
                if(i>md)vv.push_back(i);
            }
        }

        sort(vv.begin(),vv.end());


        int res = 0;
        for(int i=0; i<vv.size(); i++)
        {
            if(fun(vv[i])==true)
            {
                res = vv[i];
                break;
            }
        }

        printf("%d\n",res);
    }

    return 0;
}

/*
10
2723 + 2141 = 4344
1 + 0 = 1
0 + 1 = 1

*/
