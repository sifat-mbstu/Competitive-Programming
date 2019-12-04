#include<bits/stdc++.h>
using namespace std;

#define inf INT_MAX/3
int main()
{
    int arr[100010];
    int n,sum;
    while(cin >> n >> sum){
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int j=0, cur =0, Min = inf;
    for(int i=0; i<n;i++)
    {
        cur += arr[i];
        while(cur>=sum)
        {
//            cout <<"cur = " << cur << endl;
//            cout <<"Min = " << Min << endl;
            Min = min(Min,i-j+1);
            cur -= arr[j++];
        }
    }
    if(Min == inf) Min = 0;
    cout << Min << endl;
    }
}
