#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 2000100
ll cnt[mx];
int main()
{
    ll N,i,j;
    char str[2000100],ch;
    while(scanf("%lld",&N)==1)
    {
        memset(cnt, 0, sizeof(cnt));
        if(N==0)
        {
            break;
        }
        ch = getchar();
        gets(str);
        //puts(str);
        j = 0;
        for(i=0; i<N; i++)
        {
            if(str[i]=='Z')
            {
                cnt[j] = 0;
                j++;
                break;
            }
            else if (str[i] != 'R' && str[i] != 'D')
            {
            while(str[i] != 'R' && str[i] != 'D')
                {
                    cnt[j]++;
                    i++;
                }
                j++;
            }
            else if(((i+1) <N && str[i] == 'R' && str[i+1] != 'D') || ((i+1) <N && str[i] == 'D' && str[i+1] != 'R') )
            {
                cnt[j]++;
                j++;
            }
        }
        sort(cnt, cnt+j);
        cout << cnt[0] <<endl;
    }

}
