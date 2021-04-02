#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 50010
ll pow2[70], cum[mx];
struct node
{
    node *next[3];
    node() { next[0] = NULL; next[1] = NULL; }
}*root;

ll to_int(int *res)
{
    int j = 32;
    ll sum = 0;
    for(int i=0; i<33; i++)
    {   sum += (pow2[j]*res[i]);
        j--;
    }
    return sum;
}

void make_it(ll val, int *now)
{
    int j = 0;
    for(int i=32; i>=0; i--)
    {    if(val & pow2[i]) {now[j++] = 1;}
    else {now[j++] = 0;}
    }
}

ll check_max(int *now)
{
    node *cur = root;
    int res[150];
    for(int i=0; i<33; i++)
    {
        int id = now[i];
        if(cur -> next[!id])
        {   cur = cur -> next[!id];
            if(!id == 0) res[i] = 0;
            else res[i] = 1;
        }
        else
        {   if(cur -> next[id]==NULL) { cur -> next[id] = new node(); }
            cur = cur -> next[id];
            if(id == 0) res[i] = 0;
            else res[i] = 1;
        }
    }
    ll fin = to_int(res);
    return fin;
}

void ins(int *now)
{
    node *cur = root;
    for(int i=0; i<33; i++)
    {
        int id = now[i];
        if(cur -> next[id]==NULL) {cur ->next[id] = new node();}
        cur = cur -> next[id];
    }
}

void del(node *cur)
{
    for(int i=0 ; i<2; i++)
    {
        if(cur->next[i]) del(cur->next[i]);
    }
    delete(cur);
}

ll check_min(int *now)
{
    node *cur = root;
    int res[150];
    for(int i=0; i<33; i++)
    {
        int id = now[i];
        id = !id;
        if(cur -> next[!id])
        {
            cur = cur -> next[!id];
            if(!id == 0) res[i] = 0;
            else res[i] = 1;
        }
        else
        {
            if(cur -> next[id]==NULL) {cur -> next[id] = new node(); }
            cur = cur -> next[id];
            if(id == 0) res[i] = 0;
            else res[i] = 1;
        }
    }
    ll fin = to_int(res);
    return fin;
}

int main()
{
    pow2[0]=1;
    
    for(int i = 1; i<35; i++)
    {
        pow2[i] = pow2[i-1]<<1;
    }
    int TC, idx = 0;
    scanf("%d",&TC);
    while(TC--)
    {
        int now[150];
        ll n;
        root = new node();
        scanf("%lld",&n);
        ll arr[mx];
        for(int i=0; i<n; i++)
        {
            scanf("%lld",&arr[i]);
            if(i==0) cum[i] = arr[i];
            else cum[i] = cum[i-1]^arr[i];
        }
        ll Max = 0;
        ll Min = arr[0];
        make_it(0,now);
        ins(now);
        for(int i=0; i<n; i++)
        {
            make_it(cum[i], now);
            Max = max(Max, cum[i]^check_max(now));
            Min = min(Min, cum[i]^check_min(now));
            Min = min(Min, cum[i]);
            ins(now);
        }
        if(Max<Min) swap(Max, Min);
        printf("Case %d: %lld %lld\n",++idx, Max, Min);
        del(root);
        
    }
}
