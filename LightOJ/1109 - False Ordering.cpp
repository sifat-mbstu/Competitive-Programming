#include<bits/stdc++.h>
using namespace std;

struct Divi
{
    int val;
    int ind;
} S[1011];

bool sorter(Divi const& N1, Divi const& N2)
{
    if(N1.val != N2.val)
    {
        return N1.val<N2.val;
    }
    return N1.ind > N2.ind;

}
int Divisor(int n)
{
    int multi = 1;
    int sq = sqrt(n);
    for(int i=2; i<=sq; i++)
    {
        int cnt = 0;
        if(n%i==0)
        {
            //cout << i << endl;
            while(n%i==0)
            {
                cnt++;
                n /= i;
            }
            multi *= (cnt+1);
        }
        if(n==1) return multi;
    }
    if(n!=1) return multi*2;
    return multi;
}
int main()
{
    int i, j;
    for(int i=0; i<=1000; i++)
    {
        S[i].ind = i;
    }
    for(int i=1; i<=1000; i++)
    {
        S[i].val = Divisor(i);
    }
    sort(S+1, S+1001, &sorter);
    int TC;
    i =0;
    cin >> TC;
    while(TC--)
    {
        int a;
        cin >> a;
        printf("Case %d: %d\n",++i,S[a].ind);
    }
}
