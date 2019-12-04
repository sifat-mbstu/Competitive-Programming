#include<bits/stdc++.h>
using namespace std;
#define ll long long
map <ll, int> Map;
int main()
{
    ll Z,I,M,L,cnt,TC=0;
    while(cin >> Z >> I >> M >> L){
    if(!Z && !I && !M && !L) break;
    cnt = 0;
    Map.clear();
    while(1)
    {
        L = ((Z*L) + I ) % M ;
        Map[L]++;
        if(Map[L] == 2) break;
        cnt++;
    }
   printf("Case %lld: %lld\n",++TC,cnt);
    }
}
