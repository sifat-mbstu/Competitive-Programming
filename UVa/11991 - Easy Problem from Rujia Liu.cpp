#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector < vector <int> > vec;
    int n,m,i,res,v,k,cnt,a[100100];
    while(scanf("%d %d",&n,&m)==2)
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            vec[a[i]] = i;
        }
        while(m--)
        {
            scanf("%d %d",&k,&v);
            res = -1;
            cnt = 0;
            if(vec[v].size() <= k)
            {
                res = vec[v][k-1];
            }

            if(res != -1)
            {
                printf("%d\n",res+1);
            }
            else
            {
                printf("0\n");
            }
        }
    }
}
