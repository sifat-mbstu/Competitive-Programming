#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll L, W, H, Max_H, Max_vl, TC, V;
    while(scanf("%lld",&TC)==1)
    {
        if(!TC)break;
        Max_H = Max_vl = 0;
        while(TC--)
        {
            scanf("%lld %lld %lld",&L,&W,&H);
            V = L * W * H;
            if(Max_H <= H)
            {
                if(Max_H < H)
                {
                    Max_H = H;
                    Max_vl = V;
                }
                else
                {
                    if(Max_vl < V)
                    {
                        Max_vl = V;
                    }
                }
            }
        }
        printf("%lld\n", Max_vl);
    }
}
