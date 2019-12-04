#include<bits/stdc++.h>
using namespace std;
int arr[102];
int Map[102];
int main()
{
    int TC,ind=0;
    scanf("%d",&TC);
    while(TC--){
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&arr[i]);
        Map[arr[i]] = i;
    }
        int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(i!=arr[i])
        {
            int ind1 = i;
            int ind2 =Map[i];
            swap(arr[ind1],arr[ind2]);
            Map[arr[ind2]] = ind2;
            Map[i] = i;
            cnt++;
        }
    }
    printf("Case %d: %d\n",++ind,cnt);
    }
}
