#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll tc,TC=0;
    scanf("%lld",&tc);
    while(tc--){
    ll x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
//    if(x1==x2 || y1== y2) continue;
    ll x , y;
    ll xx = abs(x1-x2);
    ll yy = abs(y1-y2);
    ll cnt = 0;

//    ll Mn = min(x1,x2);
//    ll Mx = max(x1,x2);
//    ll cnt1 = 0;
//    for(ll i=Mn; i<=Mx; i++)
//    {
//        x = i;
//        ll v1 = (x-x1)*(y1-y2);
//        ll v3 = x1-x2;
//        if(v1%v3==0)
//        {
//            y = (v1/v3)+y1;
//            cout <<"=> " << x << " " << y << endl;
//            cnt1++;
//        }
//    }
    if(x1==x2 && y1==y2) cnt=1;
    else if(x1==x2) cnt = abs(y1-y2)+1;
    else if(y1==y2) cnt = abs(x1-x2)+1;
    else cnt = __gcd(xx,yy)+1;

//    if(cnt==cnt1) cout << "Yeah!! ok!!" << endl;
//    else cout << "OPS!!!!  = " << cnt1 << endl;
    printf("Case %lld: %lld\n",++TC,cnt);
    }
}
