
#include<bits/stdc++.h>
using namespace std;
int arr[2000010];
int pos[2000010];

int main()
{
    int TC;
    cin >> TC;
    while(TC--)
    {
        int n;
        scanf("%d",&n);
        map<int,int>Mp;
        set<int>Set;
        set<int> :: iterator it;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
            Set.insert(arr[i]);
        }
        int idx = 0;

        for(it = Set.begin(); it!=Set.end(); it++)
        {
            Mp[*it] = ++idx;
        }
        for(int i=0; i<n; i++)
        {
            arr[i] = Mp[arr[i]];
        }
        Set.clear();

        int cnt = 0;
        int st = 0;
        int Max = 0;
        for(int i=0; i<n; i++)
        {
            cnt++;
            Set.insert(arr[i]);
            Max = max(Max, (int)Set.size());
            if((int)Set.size() != cnt)
            {
                cnt--;
//                printf("st = %d .. en = %d\n",st,pos[arr[i]]);
                for(int j=st; j<pos[arr[i]]; j++)
                {
                    cnt--;
                    Set.erase(arr[j]);
                }
                st = pos[arr[i]]+1;
            }
            pos[arr[i]] = i;
//            printf("pos[%d] = %d\n",i,pos[i]);
//            Set.clear();
        }
        printf("%d\n",Max);
    }
}
