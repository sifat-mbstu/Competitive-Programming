#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int wa[500001], r8[500001];
int main()
{
    //freopen("out.txt", "w", stdout);
    ll n, st, i,j, dif, cnt_wa, cnt_r8, cnt,TC;
    cin >> TC;
    while(TC--){
    char ch;
    cin >> n;
    cnt_wa = 0, cnt_r8 = 0;
    while(n--)
    {
        cin >> dif >> st >> ch;
        if(st == 1 && ch == 'c') {r8[cnt_r8++]= dif;}
        if(st == 0 && ch == 'i') {wa[cnt_wa++] = dif;}
    }
    sort(r8, r8+cnt_r8); sort(wa, wa+cnt_wa);
    cnt = 0;
    for(i=0; i<cnt_r8;i++)
    {
        for(j=cnt_wa-1; j>=0; j--)
        {
            if(r8[i] > wa[j]){cnt+= (j+1);break;}
        }
    }
    printf("%lld\n",cnt);
    }
}
