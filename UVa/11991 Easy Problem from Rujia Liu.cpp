//*Time Limit */
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    multimap<int,int> Map;
    multimap<int,int> :: iterator it;
    int i,n,m,k,v,ara[100010],res;
    while(cin >> n >> m){
    Map.clear();
    for(i=0; i<n; i++)
    {
        scanf("%d",&ara[i]);
        Map.insert (pair<int,int>(ara[i],i));
    }
    for(i=0; i<m; i++)
    {
        scanf("%d %d",&k,&v);
        if(k > Map.count(v)) {res = 0;}
        else{
        it = Map.find(v);
        std::advance(it, k-1);
        res = (*it).second + 1;
        }
       printf("%d\n",res);
    }
}
}
*/
//New code //Accepted
#include <bits/stdc++.h>
using namespace std;
vector <int>vec[1000010];
int main()
{
    int i,n,m,k,v,a,res;
    while(cin >> n >> m){
    for(i=0; i<1000010; i++){vec[i].clear();}
    for(i=0; i<n; i++)
    {
        scanf("%d",&a);
        vec[a].push_back(i+1);
    }
    for(i=0; i<m; i++)
    {
        scanf("%d %d",&k,&v);
        if(k > vec[v].size()) {res = 0;}
        else{
        res = vec[v][k-1];
        }
       printf("%d\n",res);
    }
}
}
