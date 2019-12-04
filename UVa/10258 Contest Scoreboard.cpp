#include<bits/stdc++.h>
using namespace std;
struct st
{
    int num;
    int pen;
    int solve;
    bool is_it;
    int prob[105];
    int parr[105];
} arr[105];
bool acompare(st lhs, st rhs)
{
    if(lhs.solve!=rhs.solve) return lhs.solve > rhs.solve;

    if(lhs.pen != rhs.pen)
    {
        return lhs.pen < rhs.pen;
    }
    return lhs.num < rhs.num;
}
int main()
{
    int TC;
    bool flag = 0;
    scanf("%d",&TC);
    getchar();
    getchar();
    while(TC--)
    {
        if(flag) printf("\n");
        flag = 1;
        memset(arr,0,sizeof(arr));
        string s;
        while(getline(cin,s))
        {
            if(s=="")break;
            stringstream ss;
            ss << s;
            vector<int> vec;
            int val;
            char ch;
            while(ss >> val)
            {
                vec.push_back(val);
                if(vec.size()==3)break;
            }
            ss >> ch;
            arr[vec[0]].is_it = 1;
            arr[vec[0]].num = vec[0];
            if(ch=='C')
            {
                if(!arr[vec[0]].prob[vec[1]])
                {
                    arr[vec[0]].solve++;
                    arr[vec[0]].prob[vec[1]]=1;
                    arr[vec[0]].pen += vec[2];
                    arr[vec[0]].pen += arr[vec[0]].parr[vec[1]];
                    arr[vec[0]].parr[vec[1]] = 0;
                }
            }
            if(ch=='I')
            {
                arr[vec[0]].parr[vec[1]] += 20;
            }
        }
        sort(arr,arr+101,acompare);
        for(int i=0; i<=100; i++)
        {
            if(arr[i].is_it)
            {
                printf("%d %d %d\n",arr[i].num,arr[i].solve,arr[i].pen);
            }
        }
    }
}
