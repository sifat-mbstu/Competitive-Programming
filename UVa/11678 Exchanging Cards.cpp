#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,m,n,a;
    map<int,int>Map1;
    map<int,int> :: iterator it1;
    map<int,int>Map2;
    map<int,int> :: iterator it2;
    cin >> n >> m;
    for(i=0; i<n; i++)
    {
        cin >> a;
        Map1[a]++;
    }
    for(i=0; i<m; i++)
    {
        cin >> a;
        Map2[a]++;
    }
    for(it1 = Map1.begin(); it1 != Map1.end(); it1++)
    {
        n--;
        int val = (*it1).first;
        cout << val << endl;
        if(Map1[val] > 1) {Map1.erase(Map1.find(val));}
        if(Map2.count(val) > 0){
            if(Map1[val] == 1 && Map2[val] >= 1) {Map1.erase(Map1.find(val));}
        }
        if(Map1.size() ==0) { break;}
    }
    int len1 = Map1.size() ;

    for(it2 = Map2.begin(); it2 != Map2.end(); it2++)
    {
        int val = (*it2).first;
        cout << val << endl;
        if(Map2[val] > 1){Map2.erase(Map2.find(val));}
        if(Map2.count(val) > 0)
        {
            if(Map2[val] == 1 && Map1[val] >= 1){Map2.erase(Map2.find(val));}
        }
        if(Map2.size() ==0) break;
    }
    int len2 = Map2.size();
    cout << len1 << "=  Len1  .... Len2 ==" << len2 << endl;
    cout << min(len1, len2) << endl;
}
