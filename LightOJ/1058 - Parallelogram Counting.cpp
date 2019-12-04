///ACCEPTED
#include<bits/stdc++.h>
using namespace std;
struct st
{
    int x,y;
} arr[1010], mid[1000010];
bool cmp(st lhs, st rhs)
{
    if(lhs.x != rhs.x)
        return lhs.x < rhs.x;
    return lhs.y < rhs.y;
}

int main()
{
    int TC,idx=0;
    scanf("%d",&TC);
    while(TC--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&arr[i].x, &arr[i].y);
        }
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int mdx = (arr[i].x + arr[j].x);
                int mdy = (arr[i].y + arr[j].y);
                mid[cnt].x = mdx;
                mid[cnt++].y = mdy;
            }
        }
        sort(mid,mid+cnt,&cmp);
        long long res = 0;
        for(int i=0; i<cnt; i++)
        {
            long long cur = 1;
            if(i+1<cnt && (mid[i].x == mid[i+1].x) && (mid[i].y == mid[i+1].y))
            {
                while(i+1<cnt &&(mid[i].x == mid[i+1].x) && (mid[i].y == mid[i+1].y))
                {
                    i++;
                    cur++;
                }
                i--;
            }
            res += (cur*(cur-1))/2;
        }
        printf("Case %d: %lld\n",++idx,res);
    }
}
