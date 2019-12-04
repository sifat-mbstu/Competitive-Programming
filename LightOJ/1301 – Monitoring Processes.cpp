#include<bits/stdc++.h>
using namespace std;
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)

#define pii pair<int,int>
struct st{
    int l, r;
    st(){}
    st(int _l, int _r)
    {
        l = _l;
        r = _r;
    }
    bool operator<(const st&ob)const
    {
        if(l != ob.l)
            return l < ob.l;

        return r < ob.r;
    }
}arr[51000];
multiset<st>Set;
multiset<st> :: iterator it;
int main()
{
//    FO;
    int TC,cas=0;
    cin >> TC;
    while(TC--){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
//        int a,b;
        scanf("%d %d",&arr[i].l, &arr[i].r);
//        arr[i] = pii(a,b);
        Set.insert(arr[i]);
    }
    int cnt = 0;
    while(!Set.empty())
    {
        int pre = -1;
        int idx = 0;
        for(it = Set.begin(); it!= Set.end(); it++)
        {
            int cur1 = (*it).l;
            int cur2 = (*it).r;
            if(cur1>pre)
            {
                arr[idx++] = (*it);
                pre = cur2;
            }
//            cout << "pre = " << pre << endl;
        }
        cnt++;
        for(int i=0; i<idx; i++)
        {
            it = Set.find(arr[i]);
//            cout << arr[i].l << " ==0" << endl;
            Set.erase(it);
        }
        for(it = Set.begin(); it!= Set.end(); it++)
        {
            int cur1 = (*it).l;
            int cur2 = (*it).r;
//            cout << cur1 << " " << cur2 << endl;
        }
//        getchar();
//        getchar();
    }
    printf("Case %d: %d\n",++cas,cnt);
    }
}
