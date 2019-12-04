#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 100000010
ll ara[MX],ara_1[MX];
int main()
{
    ll N, S, res,i,j,k,sum;
    cin >> N >> S;
    res = 1, sum =0, k=0;
    for(i=0; i<N; i++)
    {
        cin >> ara[i];
    }
    sort(ara, ara+N);
    for(i=N-1; i>=0; i--)
    {
        if(ara[i]==S)
        {
            res = 1;
            break;
        }
        if(ara[i] < S)
        {
            for(j = i; j<=0; j--)
            {
                sum = sum + ara[j];
                printf("ara[j");
                printf("sum = %lld\n",sum);
                res++;
                if(sum > S) {sum = 0; break;}
                if(sum == S)
                {
                    //cout << "res" << res << endl;
                    if(res>0)
                    {
                        ara_1[k]=res;
                        k++;
                        res=0;
                    }
                    sum = 0;
                    break;
                }
            }
        }
    }
    sort(ara_1, ara_1+k);
    cout << ara_1[0];
}
