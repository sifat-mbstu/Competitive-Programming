#include<bits/stdc++.h>
using namespace std;
#define FI freopen ("input.txt", "r", stdin);
#define FO freopen ("output.txt", "w", stdout);
int main()
{
   // FI;FO;
    map<int ,int> mymap;
    map<int, int>:: iterator  it;
    int i, n, l, a, b;
    while(cin >> n)
    {
        if(!n) break;
        mymap.clear();
        cin >> l;
        for(i=0; i < l; i++)
        {
            cin >> a >> b;
            mymap[a]++;
            mymap[b]++;
        }
        int bicolor3 = 0;
        int bicolor2 = 0;
        int bicolor = 0;
        for(i = 0; i < n; i++)
        {
        // cout << "mymap[" << i << "] = " << mymap[i] << endl;
            if(mymap[i] < 2){
                bicolor++;
            }
            else if(mymap[i] == 2){
                bicolor2++;
            }
            else bicolor3++;
        }
        //cout << "bicolor = " << bicolor << endl;
        if((bicolor3 > 1) || (bicolor2 == n) || ((bicolor3 == 1) && (bicolor2 > 0))) {cout << "NOT BICOLORABLE.\n";}
        else {cout << "BICOLORABLE.\n";}

    }

}
