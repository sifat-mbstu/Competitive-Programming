///Accepted
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,num,i;
    vector <int> vec;
    vector <int> :: iterator v;
    map <vector<int> ,int > Map;
    map <vector<int> ,int > :: iterator it;
    while(cin >> n){
        if(!n) break;
    while(n--)
    {
        vec.clear();
        k = 5;
        while(k--)
        {
            cin >> num;
            vec.push_back(num);
        }
        sort(vec.begin(), vec.end());
        /*for(v = vec.begin(); v!= vec.end(); v++)
        {
            cout << (*v) << endl;
        }*/
        Map[vec]++;
    }
    int Max = 0,ara[10050],j=0;
    for(it = Map.begin(); it != Map.end(); it++)
    {
        int p = (*it).second;
        ara[j] = p;
        if(p > Max) Max =p;
        j++;
    }
    int sum = 0;
    sort(ara,ara+j);
    for(i = j-1; i >= 0; i--)
    {
        if(ara[i] == Max){sum += ara[i];}
        else{break;}
    }
    cout << sum << endl;
    Map.clear();
    }
}
