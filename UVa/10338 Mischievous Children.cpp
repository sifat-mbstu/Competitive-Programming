#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll a[25], f[25];
int main()
{
    memset(a, 1, sizeof(a));
    string s;
    ll n,m,TC,i,j,k;
    cin >> TC;
    for(int x = 1; x <= TC; x++)
    {
        cin >> s;
       // sort(s.begin(), s.end());
       // cout << s << endl;
        map<char,int>Map;
        map<char,int> :: iterator it;
        int len = s.size();
        for(i=0; i<len; i++)
        {
            Map[s[i]]++;
        }
        int m = 0;
        for(it = Map.begin(); it != Map.end(); it++)
        {
            int p = (*it).second;
            if( p > 1)
            {
                ll multi = 1;
                for(int z = p; z >= 2; z--)
                {
                    multi *= z;
                }
                a[m] = multi;
                //cout << multi <<endl;
                m++;
            }
        }
        sort(a,a+m);
        int j=m-1;
        ll multi = 1;
        for(i=len; i>=2; i--)
        {
            k = i;
            multi *= k;
            if(m !=0)
            {
                while(j >= 0 && (multi%a[j]) == 0)
                {
                    multi /= a[j];
                    j--;
                }
            }
            //cout << k << "  " << multi << endl;

        }
        printf("Data set %d: %llu\n",x,multi);
    }
}
