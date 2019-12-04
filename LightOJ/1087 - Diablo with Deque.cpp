#include<bits/stdc++.h>
using namespace std;
int main()
{
    int TC, ind =0;
    scanf("%d",&TC);
    while(TC--){
    vector<int>DQ;
    int n,m;
    scanf("%d %d",&n, &m);
    for(int i=0; i<n; i++)
    {
        int val;
        scanf("%d",&val);
        DQ.push_back(val);
    }
    printf("Case %d:\n",++ind);
    for(int i=0; i<m; i++)
    {
        getchar();
        char ch,cc;
        int val;
        scanf("%c%c%d",&ch,&cc,&val);
        if(ch=='c')
        {
            if(DQ.size()<val){printf("none\n");continue;}
            printf("%d\n",DQ[val-1]);
            DQ.erase(DQ.begin()+val-1);
        }
        if(ch=='a')
        {
            DQ.push_back(val);
        }
    }
    }
}
