#include<bits/stdc++.h>
using namespace std;
#define MAx 10000000
#define ll long long unsigned
ll jack[MAx], jil[MAx];
int main()
{
    ll N,M,i,j,cnt;
    while(cin >> M >> N)
    {
        if(M==0 && N==0)
        {
            break;
        }
        cnt = 0;
        for(i=0; i<N; i++)
        {
            cin >> jack[i];
        }
        j = 0;
        for(i=0; i<M; i++)
        {
            cin >> jil[i];
            while(j<N)
            {
                if(jil[i]==jack[j])
                {
                    cnt++;
                }
                else
                {
                    if(jil[i] < jack[j])
                    {
                        break;
                    }
                }
                j++;
            }
        }
        cout << cnt << endl;
    }
}
