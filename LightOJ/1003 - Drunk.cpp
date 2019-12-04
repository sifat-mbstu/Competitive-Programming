#include<bits/stdc++.h>
using namespace std;
map<string, int> Map;
map<string, int> :: iterator it;

#define M 10001
vector<int> depends[M];
int taken[M];
int cycle = 0;
void reset()
{
    cycle =0;
    for(int i=0; i<M; i++)
    {
        taken[i] = 0;
        depends[i].clear();
    }
}
void take( int p )
{
//    cout << "p = " << p << "taken " << taken[p] << endl;
//    getchar();
    if(taken[p]==2 || cycle)
    {
//        cout << "Hmm 1";
        return;
    }
    if(taken[p]==1)
    {
//                cout << "Hmm 2";
        cycle = 1;
        return;
    }
    taken[p] = 1;
    for(int i=0; i<depends[p].size(); i++)
    {
//          printf("depend = %d\n",depends[p][i]);
        take(depends[p][i]);
    }
    taken[p] = 2;
    //ans.push_back(p);
}

int main()
{
    int TC,index=0;
    cin >> TC;
    while(TC--){
    reset();
    int n, u ,v;
    cin >> n;
    int ind = 0;
    while(n--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if(Map[s1]<=0)
        {
            Map[s1] = ind++;
        }
        if(Map[s2]<=0)
        {
            Map[s2] = ind++;
        }
        u = Map[s1];
        v = Map[s2];
        depends[u].push_back(v);
    }
    for(it = Map.begin(); it != Map.end(); it++)
    {
        int val = (*it).second;
        if(!taken[val]) take(val);
    }
    if(!cycle)
    {
        printf("Case %d: Yes\n",++index);
//        cout << "NO" << endl;
    }
    else
    {
        printf("Case %d: No\n",++index);
//        cout << "YES" << endl;
    }
    Map.clear();
    }
}
