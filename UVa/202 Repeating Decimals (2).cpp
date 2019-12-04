#include<bits/stdc++.h>
using namespace std;
int main()
{
    bool flag = 0;
    int u,v;
    while(cin >> u >> v)
    {
        int mk[100000],res[100000];
        memset(mk,-1,sizeof(mk));
        int div = u/v;
        int extra = u - (div*v);
        int idx = 0;
        while(mk[extra]==-1)
        {
            if(extra==0)break;
            mk[extra]=idx;
            extra *= 10;
            res[idx] = extra/v;
            extra -= (res[idx]*v);

            idx++;
        }
        cout << u << "/" << v << " = ";
        cout << div << ".";
        for(int i=0; i<idx; i++)
        {
            if(extra!=0 && i==mk[extra])
            {
                cout << "(";
            }
            cout << res[i];
            if(i==49 && i+1<idx)
            {
                cout << "...";
                break;
            }
        }
        if(extra==0) cout << "(0)" << endl;
        else cout << ")" << endl;
        int len;
        if(extra == 0) len = 1;
        else len = idx-mk[extra];
        cout << "   " << len << " = number of digits in repeating cycle\n";
        cout << endl;
    }
}
