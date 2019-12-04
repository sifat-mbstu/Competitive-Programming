#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string keyword[100], excuses[100];
    ll k,e,i,cnt[1000],f,j;
    cin >> k >> e;
    memset(cnt, 0, sizeof(cnt));
    getchar();
    for(i=0;i<k;i++)
    {
        getline(cin, keyword[i]);
    }
    for(i=0;i<e;i++)
    {
        getline(cin, excuses[i]);
        f = -1;
        for(j=0; j < k; j++)
        {
            while(f != string::npos){
                f = excuses[i].find(keyword[j],f+1);
                if(f>=0) cnt[i]++;
            }
        }
    }
    for(i = 0; i< e;i++)
    {
        cout << cnt[i] <<endl;
    }
}
