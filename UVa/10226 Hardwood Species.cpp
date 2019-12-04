#include<bits/stdc++.h>
using namespace std;
int main()
{
    map <string , int> Map;
    map <string , int> :: iterator it;
    char ch, tree[100];
    int n, tot;
   scanf("%d\n\n",&n);
   while(n--)
   {
       tot = 0;
        Map.clear();
        while(gets(tree))
        {
            int len = strlen (tree);
            if(len == 0) break;
            else{
            Map[tree]++;
            tot++;
        }
        }
        for(it = Map.begin(); it!= Map.end(); it++)
        {
            printf("%s %.4lf\n",(*it).first.data(), (double)(*it).second / (double) tot * 100.0);
        }
        if(n>0)cout << endl;
   }

}
