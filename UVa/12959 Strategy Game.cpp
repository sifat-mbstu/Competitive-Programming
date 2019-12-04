#include<bits/stdc++.h>
using namespace std;
int main()
{
    map <int, int>Map;
    int J, R, i ,j, a;
    while(cin >> J >> R){
    Map.clear();
    for(j =1 ; j<=R; j++)
    {
        for(i=1; i<=J; i++)
        {
            cin >> a;
            Map[i] += a;
        }
    }
    int Max = 0, res;
    for(i=1; i<= J; i++)
    {
        if(Max <= Map[i])
        {
            Max = Map[i];
            res = i ;
        }
    }
    cout << res << endl;
    }
}
