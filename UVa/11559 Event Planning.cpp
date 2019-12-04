///Accepted
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    ll N, B, H, W, expense, min_bud, week, i, t, tot;
    while(cin >> N >> B >> H >> W){
    min_bud = B+1 ;
    bool TT = 0;
    for(i = 0; i < H; i++)
    {
        cin >> expense;
        t = 1;
        for( int j = 0; j < W; j++)
        {
            cin >> week;
            if(week >= N)
            {
                //cout << " T mama \n";
                t = 1;
            }
        }
        if(t){tot = N * expense;
        //cout << tot << endl;
            if(tot <= B) {min_bud = min(min_bud, tot);}
        }
    }
    if(min_bud <= B) cout << min_bud << endl;
    else{cout << "stay home" << endl;}
    }
}
/**
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,B,H,W,p,ans,cap;

    while(scanf("%d %d %d %d",&N,&B,&H,&W) == 4){
        ans = B + 1;

        for(int i = 0;i < H;++i){
            scanf("%d",&p);
            cap = 0;

            for(int j = 0,x;j < W;++j){
                scanf("%d",&x);
                cap = max(cap,x);
            }

            if(cap >= N) ans = min(ans,N * p);
        }

        if(ans == B+1) puts("stay home");
        else printf("%d\n",ans);
    }

    return 0;
}
*/
