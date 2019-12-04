#include<bits/stdc++.h>
using namespace std;
int a[26][26], n;
bool check_row_col()
{
    set <int> s1, s2;
    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n; j++)
        {
            s1.insert(a[i][j]);
            s2.insert(a[j][i]);
        }
        if(s1.size() != n || s2.size() != n){return 0;}
        s1.clear(); s2.clear();
    }
    return 1;
}
bool check_sqrt_box(int sq)
{
    set <int> s;
    for(int i=0; i<n; i+=sq)
    {
        for(int k=0; k<n; k+=sq)
        {
            for(int j=i; j<i+sq; j++)
            {
                for(int m=k; m<k+sq; m++)
                {
                    //printf("a[j][m] = %d \n", a[j][m]);
                    s.insert(a[j][m]);
                }
                //printf("\n");
            }
            if(s.size()!= n){return 0;}
            s.clear();
        }
    }
    return 1;
}

int main()
{
    int TC;
    scanf("%d",&TC);
    while(TC--){
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int sq = round(sqrt((double)n));
    bool res1, res2;
    res1 = check_row_col();
    res2 = check_sqrt_box(sq);
    if(res1 && res2){printf("yes\n");}
    else {printf("no\n");}
    }
}
