#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,num,sum;
    priority_queue < int , vector<int>, greater < int > > pq;
    while(cin >> n)
    {
        if(n==0) break;
    for(i =0; i < n; i++)
    {
        cin >> num;
        pq.push(num);
    }
    sum = 0;
    while(pq.size() > 1)
    {
        num = pq.top();
        pq.pop();
        num += pq.top();
        pq.pop();
        sum += num;
        pq.push(num);
    }
    cout << sum << endl;
    pq.pop();
    }
}
