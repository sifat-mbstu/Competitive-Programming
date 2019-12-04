#include<bits/stdc++.h>
using namespace std;
int main()
{
    int TC, ind = 0;
    scanf("%d",&TC);
    while(TC--){
    int n;
    stack<int> st;
    scanf("%d",&n);
    int arr[n+1];
    for(int i=0; i<n; i++) {scanf("%d",&arr[i]);}
    int cur = 0;
    int cur_area;
    int Maxi = 0;
    while(cur<n)
    {
        if(st.empty() || arr[st.top()]<= arr[cur])
        {
            st.push(cur);
            cur++;
        }
        else
        {
            int TOP = st.top();
            st.pop();
//            cout << "TOP1 = " << TOP  << endl;
            if(st.empty())
            {
                cur_area = arr[TOP]*cur;
//                cout << "1. cur_area => " << cur_area << endl;
            }
            else
            {
                cur_area = arr[TOP] * (cur - st.top() - 1);
//                cout << "2. cur_area => " << cur_area << endl;
            }
            Maxi = max(Maxi, cur_area);
        }
    }
    while(!st.empty())
    {
            int TOP = st.top();
            st.pop();
//            cout << "TOP = " << TOP  << endl;
            if(st.empty())
            {
                cur_area = arr[TOP]*cur;
//                cout << "3. cur_area => " << cur_area << endl;
            }
            else
            {
                cur_area = arr[TOP] * (cur - st.top() - 1);
//                cout << "4. cur_area => " << cur_area << endl;
            }
            Maxi = max(Maxi, cur_area);
    }
    printf("Case %d: %d\n",++ind, Maxi);
    }
}
