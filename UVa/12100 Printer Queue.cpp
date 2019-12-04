#include<bits/stdc++.h>
using namespace std;
struct st
{
    int pr,idx;
}arr[200];
int main()
{
    int TC;
    cin >> TC;
    while(TC--){
    int n,m;
    cin >> n >> m;
    queue<st>q;
    priority_queue<int> pq;
    for(int i=0; i<n; i++)
    {
        int v;
        cin >> v;

        st now;
        now.idx = i;
        now.pr = v;

        arr[i] = now;
        pq.push(v);
    }
    for(int i=0; i<n; i++)
    {
        q.push(arr[i]);
    }
    int cnt = 0;
    while(!q.empty())
    {
        int cur = q.front().pr;
        int hi = pq.top();
        if(hi > cur)
        {
            q.push(q.front());
            q.pop();

        }
        else
        {
            cnt++;
            if(q.front().idx==m) break;
            q.pop();
            pq.pop();
        }
    }
    cout << cnt << endl;
    }
}
