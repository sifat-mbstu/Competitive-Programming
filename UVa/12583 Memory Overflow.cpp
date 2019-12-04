#include<bits/stdc++.h>
using namespace std;
#define FI freopen("input.txt", "r", stdin)
#define FO freopen("output.txt", "w", stdout)
#define ll long long
int main()
{
    //FI,FO;
    string s;
    ll len,i,j,n,x,TC,k;
    cin >> TC;
    for(x=1; x<=TC; x++)
    {
        cin >> n >> k >> s;
        ll rec = 0;
        len = s.size();
        ll a[100000];
        ll h = 0,cnt = 0;
        for(j = 0; j< len; j++)
        {
            //cout << "huh";
            for( i = j+1; i < len && i <= j+k; i++)
            {
                if(s[j] == s[i] && s[i] != '*')
                {
                    //cout << s << endl;
                    //printf("i = %d j = %d ",i,j);
                    //cout <<"s[i]= " <<s[i] << " s[j] = "<<s[j] << endl;
                    a[h] = i;
                    cnt++;
                    h++;
                    if(cnt > 1){s[a[h-2]] = '*';}
                }
            }
            rec += cnt;
            cnt = 0;
            h = 0;
        }
        printf("Case %lld: %lld\n",x,rec);
    }
}
