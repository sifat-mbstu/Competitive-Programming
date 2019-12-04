#include<bits/stdc++.h>
using namespace std;
#define FI freopen("input.txt", "r", stdin)
#define FO freopen("output.txt", "w", stdout)
string s;
int res = 0;
int finding_dot(int i, int j)
{
    int cnt = 0;
    for(int x = i; x < j ; x++)
    {
        if(s[x] == '.')
        {
            cnt++;
        }
        else{
            break;
        }
    }
    return cnt;
}
void finding_hash()
{
    int len = s.size();
    for(int i = 1; i < len-1; i++)
    {
        if(s[i] == '#' && s[i-1] == '.' && s[i+1] == '.')
        {
            int cnt1 = finding_dot(0,i);
            int cnt2 = finding_dot(i+1,len);
            if((cnt1%3 !=0) && (cnt2%3 !=0))
            {
                s.erase( i-1, 3);
                len = s.size();
                finding_hash();
                res++;
            }
        }
    }
}
int main()
{
    FI;
    int TC,N;
    cin >> TC;
    for(int k=1;k<=TC;k++){

    cin >>N ;
    //char c = getchar();
    cin >> s;
    res = 0;
    finding_hash();
    //cout << res <<endl << s << endl;
    int len = s.size();
    int cnt =0, i;
    double fer = 0.0;
    for(i=0; i<len; i++)
    {
        if(s[i] == '.')
        {
            fer++;
        }
        else{
            int a= ceil((double) (fer/3.0));
            cnt += a;
            fer = 0.0;
        }
    }
    cnt += ceil((double) (fer/3.0));
    printf("Case %d: %d\n",k,cnt+res);
    }
}
