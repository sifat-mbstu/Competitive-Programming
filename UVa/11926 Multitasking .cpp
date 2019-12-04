#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector<pii>P;
int main()
{
    int n,m;
    while(scanf("%d %d",&n, &m)==2){
            if(!n && !m)break;
    P.clear();
//    int idx = 0;
    for(int i=0; i<n; i++)
    {
        int a,b;
        scanf("%d %d",&a, &b);
        P.push_back(pii(a,b));
    }

    for(int i=0; i<m; i++)
    {
        int a,b,cycle;
        scanf("%d %d %d",&a, &b, &cycle);
        int inter = abs(a-b);
        while(1)
        {
//            P[idx++] = pii(a,b);
        P.push_back(pii(a,b));
            a += cycle;
            b += cycle;
            if(a>1000000)break;
            if(b>1000000)
            {
            P.push_back(pii(a,1000000));
//                P[idx++] = pii(a,);
                break;
            }
        }
    }
    sort(P.begin(),P.end());
    bool yes = 1;
    for(int i=0; i<P.size()-1; i++)
    {
//        int a1 = P[idx].first;
        int b1 = P[i].second;
        int a2 = P[i+1].first;
//        int b2 = P[idx].second;
//        cout << b1 << " == " << a2 << endl;
        if(b1>a2) {yes = 0; break;}
    }
    if(yes) printf("NO CONFLICT\n");
    else printf("CONFLICT\n");
    }
}
