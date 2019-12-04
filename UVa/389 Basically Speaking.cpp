#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string n,res;
    ll deci,base1, base2;
    while(cin >> n >> base1 >> base2)
    {
        res.clear();
        deci = 0;
        int len = n.size(), j = 0,num;
        for(int i=len-1; i>=0; i--)
        {
            if(n[i] >= '0' && n[i] <= '9') num = n[i] - '0';
            else if(n[i] >= 'A' && n[i] <= 'F') num = n[i] - 'A' + 10;
            ll m = round((double) pow((double)base1,(double)j));
            deci += m*num;
            j++;
        }

        if(base2 == 10)
        {
            int dig = floor(log10(deci)) + 1;
            if(dig < 8) printf("%7lld\n",deci);
            else cout << "  ERROR" <<endl;
        }
        else
        {
            while(deci != 0)
            {
                int num = deci % base2;
                //cout << num << endl;
                if(num < 10)
                {
                    res.push_back(num +'0');
                }
                else if(num > 9)
                {
                    res.push_back(num+'A' - 10);
                }
                deci /= base2;
            }
            reverse(res.begin(), res.end());
            if(res.empty()){res.push_back('0');}
            if(res.size() < 8) cout << setw(7) << res << endl;
            else cout << "  ERROR" << endl;
        }
    }
}
