#include<bits/stdc++.h>
using namespace std;
int k;
string s;
int DP[15][2][100][100];

int is_divisible(string ss)
{
    int rem = 0, sum = 0;
    for(int i=0; i<ss.size(); i++)
    {
        sum += (ss[i]-'0');
        rem = rem * 10 + (ss[i]-'0');
        rem = rem % k;
    }
    if(sum % k != 0) rem = 1;
    if(rem) {return 0;}
    else {return 1;}
}

int fun(int pos, int stat, int sum, int rem)
{
    if(DP[pos][stat][sum][rem] != -1) return DP[pos][stat][sum][rem];
    if(pos == s.size())
    {
        if(sum%k == 0 && rem % k == 0 ) return 1;
        else return 0;
    }
    int hi = 9, lo = 0, res=0;
    if(!stat)
    {
        hi = s[pos]-'0';
    }
    for(int i=lo; i<=hi; i++)
        res += fun(pos+1, stat||i<hi, sum+i, (rem*10+i)%k);
    DP[pos][stat][sum][rem] = res;
    return res;
}

int main()
{
    int TC, ind = 0, ans;
    cin >> TC;
    while(TC--)
    {
        string x, y;
        cin >> x >> y >> k;
        if(k > 90)
        {
            ans = 0;
        }
        else
        {
            memset(DP, -1, sizeof(DP));
            s = x;
            int x1 = fun(0,0,0,0);
            memset(DP, -1, sizeof(DP));
            s = y;
            int x2 = fun(0,0,0,0);
            ans = x2 - x1 + is_divisible(x);
        }
        printf("Case %d: %d\n",++ind, ans);
    }
}
