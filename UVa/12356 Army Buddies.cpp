#include<bits/stdc++.h>
using namespace std;
set<int>SET;
set<int> :: iterator it, it1, it2;
int main()
{
    int s,b;
    while(scanf("%d %d",&s,&b)==2)
    {
        if(!s && !b) break;
        SET.clear();
        for(int i=1; i<=s; i++)
        {
            SET.insert(i);
        }
        while(b--)
        {
            int ansl=0,ansr=0;
            int l,r;
            scanf("%d %d",&l, &r);

            it = SET.find(l);
            if(it==SET.begin())
            {
                ansl = -1;
            }
            else
            {
                it = SET.lower_bound(l);
                it--;
                ansl = *it;
            }

            it = SET.find(r);
            it++;
            if(it==SET.end())
            {
                ansr = -1;
//            cout << "ho" << endl;
            }
            else
            {
                it = SET.upper_bound(r);
//            it++;
                ansr = *it;
            }

//            cout << "ANS =  " ;
            if(ansl==-1) printf("*");
            else printf("%d",ansl);

            if(ansr==-1) printf(" *\n");
            else printf(" %d\n",ansr);

            it1 = SET.lower_bound(l);
            it2 = SET.upper_bound(r);
            SET.erase(it1,it2);
        }
        printf("-\n");
    }
}
