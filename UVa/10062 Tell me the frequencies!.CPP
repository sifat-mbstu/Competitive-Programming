#include<bits/stdc++.h>
using namespace std;
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
int main()
{
    //FI;FO;
    int ara[230];
    int N, i , freq,ascii;
    string s;
    pair<int , int> Pair[1001];
    set<int> Set;
    set<int> :: iterator it;
    int t = 0;
    while(getline(cin, s)){
    memset(ara, 0, sizeof(ara));
    for(i = 0; i < s.size();i++)
    {
        if(s[i] < 128 && s[i] >= 32){
        int a = s[i];
        ara[a]++;
        Set.insert(a);
        }
    }
    i = 0;
    for(it = Set.begin(); it != Set.end(); it++)
    {
        ascii = *it;
        freq = ara[ascii];
        ascii = (-1) * ascii;
        Pair[i] = make_pair(freq, ascii);
        i++;
    }
    N = Set.size();

    sort(Pair, Pair+N);

    if(t !=0) cout << endl;
    for(i=0; i<N; i++)
    {
       cout << Pair[i].second * (-1) <<  " " << Pair[i].first << endl;
    }
    Set.clear();
    //Pair.clear();
    t = 1;
}
}
