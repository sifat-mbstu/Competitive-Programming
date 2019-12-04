///Check how many substring are palindrome
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("output.txt","w",stdout);
    string given,rev,sub;
    int len,i,j,p,counts = 0,x,y,k,set_len;
    while(getline(cin,given)){
    counts = 0;
    len = given.size();
    set<char>Set;
    map <string , int> Map;
    for(i=0; i<len; i++)
    {
        Set.insert(given[i]);
        k = 0;
        p = i;
        sub.clear();
        for(j=i; j < len; j++)
        {
            sub.push_back(given[p]);
            p++;
            k++;
            y = 0;
            rev = sub;
            reverse(rev.begin(), rev.end());
            //cout << sub << endl;
/*            for(x = k-1; x >= 0; x--)
            {
                rev[x] = sub[y];
                y++;
            }*/
            if(k>1 && sub==rev)
            {
                Map[sub]++;
            }
        }
    }
    cout << "The string '" << given << "' contains " << Map.size()+Set.size() << " palindromes.\n" ;
    }
}
