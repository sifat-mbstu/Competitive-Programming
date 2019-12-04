#include<bits/stdc++.h>
using namespace std;
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)

    int arr[20],mk[20], n;
bool is_prime(int val)
{
    for(int i=2; i<val; i++)
    {
        if(val%i==0)
        {
            return 0;
        }
    }
    return 1;
}
void fun(int pos)
{
    if(pos==n)
    {
        if(is_prime(arr[pos-1]+1))
        {
            printf("%d",arr[0]);
            for(int i=1; i<n; i++)
            {
                printf(" %d",arr[i]);
            }
            printf("\n");
        }
        return;
    }
    for(int i=2; i<=n; i++)
    {
        if(mk[i]==0)
        {
            if(is_prime(arr[pos-1]+i))
            {
                arr[pos] = i;
                mk[i]=1;
                fun(pos+1);
                mk[i]=0;
            }
        }
    }
//    mk[arr[pos]]=0;
}
int main()
{
//    FO;
    int idx = 0;
    bool flag = 0;
    while(scanf("%d",&n)==1){
    if(flag) printf("\n");
    flag = 1;
    printf("Case %d:\n",++idx);
    arr[0] = 1;
    fun(1);
    }
}
