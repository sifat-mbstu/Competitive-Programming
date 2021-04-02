#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
string s;
int sz;
int dp[19][1025][2][2];

int fun(int pos, int mask, int suru, int choto)
{
    if(pos==sz)
    {
        if(suru==0) return 0;
        int cnt = __builtin_popcount(mask);
        int Max;
        for(int i=10; i>=0; i--)
        {
            if(mask&(1<<i))
            {
                Max = i;
                break;
            }
        }
        if(Max==cnt) return 1;
        return 0;
    }

    int &ret = dp[pos][mask][suru][choto];
    if(ret!=-1 && suru && choto) return ret;

    int lo = 0;
    int hi = 9;
    if(choto==0)
    {
        hi = s[pos]-'0';
    }
    ret = 0;
    for(int i=lo; i<=hi; i++)
    {
        int nmsk = mask;
        if(suru | (i>0)) nmsk = mask|(1<<i);
        ret += fun(pos+1, nmsk, suru|(i>0), choto|(i<hi));
    }
    return ret;
}

int main()
{
    int tc;
    scanf("%d",&tc);
    memset(dp,-1,sizeof(dp));
    while(tc--)
    {
        cin >> s;
        while(s.size()<18)
        {
            s.insert(s.begin(),'0');
        }
        sz = s.size();
        int res = fun(0,0,0,0);
        printf("%d\n",res);
    }
}
