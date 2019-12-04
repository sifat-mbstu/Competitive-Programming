///accepted
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,i,a[10010],cnt;
    while(cin >> N)
    {
        if(N==0)
        {
            break;
        }
        cnt = 0;
        for(i = 1; i <= N; i++)
        {
            cin >> a[i];
        }
        if(N>1)
        {
            a[0] = a[N];
            a[N+1] = a[1];
            for(i = 1; i <= N; i++)
            {
                if((a[i] > a[i+1]) && (a[i] > a[i-1]))
                {
                    cnt++;
                }
                if((a[i] < a[i+1]) && (a[i] < a[i-1]))
                {
                    cnt++;
                }
            }
        }
        cout << cnt <<endl;
    }
}
