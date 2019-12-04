#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N, a[20], b[20], c[20],  i, carry[20],res[20],dif,sum,x = 0;
    while(cin >> N){
    if(N < 0) break;
    memset(res, -1, sizeof(res));
    memset(carry, 0, sizeof(carry));
    carry[0] = N;
    for(i = 0; i < 12; i++){cin >> a[i];}
    for(i = 0; i < 12; i++){cin >> b[i];}
   for(i = 0; i < 12; i++)
    {
        //printf("Carry1 = %d  Carry2 = %d", carry)

        if(i == 2){carry[0] = 0;}
        if(i ==0){
            if(a[i] < b[i])
            {
                dif = b[i] - a[i];
                if(carry[0] >= dif)
                {
                    carry[0] -= dif;
                    dif = 0;
                    res[i] = 0;
                }
            }
        }
        else if(i==1)
        {
            if(a[i] < b[i])
            {
                sum = carry[0] + carry[1];
                dif = b[i] - a[i];
                if(dif <= sum)
                {
                    res[i] = 0;
                    dif -= carry[0];
                    carry[0] -= dif;
                    if(carry[0] < 0){carry[0] = 0;}
                    if(dif <= 0) dif = 0;
                    else
                    {
                        carry[1] -= dif;
                        dif = 0;
                    }
                }
            }
        }
        else
        {
            if(a[i] < b[i])
            {
                sum = carry[1] + carry[2] + carry[3];
                dif = b[i] - a[i];
                if(dif <= sum)
                {
                    res[i] = 0;
                    dif -= carry[1];
                    carry[1] -= dif;
                    if(carry[1] < 0){carry[1] = 0;}
                    if(dif <= 0) dif = 0;
                    else
                    {
                        carry[2] -= dif;
                        dif -= carry[2];
                    }

                    if(carry[2] < 0){carry[2] = 0;}
                    if(dif <= 0) dif = 0;
                    else
                    {
                        carry[3] -= dif;
                        dif -= carry[3];
                    }
                    if(carry[3] < 0){carry[3] = 0;}
                    if(dif <= 0) dif = 0;
                }
            }
        }

        if(i%3 ==0)
        {
            if(a[i] >= b[i]) {
                res[i] = 0;
                carry[1] = a[i] - b[i];
            }
            carry[2] = 0;
        }

        if(i%3 == 1)
        {
            if(a[i] >= b[i]) {
                res[i] = 0;
                carry[2] = a[i] - b[i];
            }
            carry[3] = 0;
        }
        if(i%3 == 2)
        {
            if(a[i] >= b[i]) {
                res[i] = 0;
                carry[3] = a[i] - b[i];
            }
            carry[1] = 0;
        }
    }
    printf("Case %d:\n",++x);
    for(i = 0; i < 12; i++)
    {
        if(res[i] != -1)
        {
            printf("No problem! :D\n");
        }
        else
        {
            printf("No problem. :(\n");
        }
    }
    }
}
