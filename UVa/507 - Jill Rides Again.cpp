#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll Max = 0;
ll ara[20010];
ll st,en;
ll n;
ll fin_ini = 0, fin_end = 0;
void kadane()
{
    ll sum = 0, s = 0,e = 0;
    int dif = 0;
    for(ll i=0; i<n; i++)
    {
        sum += ara[i];
        if(sum < 0)
        {
            sum = 0;
            s = i+1;
        }
        if(Max<=sum && sum!=0)
        {
            en = i;
            st = s;
            int d = en - st + 1;
            if ((Max == sum && dif < d) || (Max < sum))
            {
                dif = d;
                fin_ini = st;
                fin_end = en;
            }
            Max = sum;
        }
    }
}

int main()
{
    ll TC, ind =0;
    scanf("%lld",&TC);
    while(TC--)
    {
        scanf("%lld",&n);
        --n;
        for(ll i=0; i<n; i++)
        {
            scanf("%lld",&ara[i]);
        }
        st = 0;
        en = -1;
        Max = 0;
        kadane();
//        cout << en << endl;
        if(en != -1) printf("The nicest part of route %lld is between stops %lld and %lld\n",++ind, fin_ini+1,fin_end+2);
        else
        {
            printf("Route %lld has no nice parts\n",++ind);
        }
//    cout << Max <<  " = Max .... " << st << "= st ... en =" << en << endl;
    }
}
