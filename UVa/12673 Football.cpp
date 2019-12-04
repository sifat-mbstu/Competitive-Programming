#include<bits/stdc++.h>
using namespace std;
#define MAX 1100000
int ara[MAX];
int main()
{
    int N, G, S, R, i, j, k, points ;
    while(cin >> N >> G)
    {
        points = k = 0;
        for(i=0; i < N; i++)
        {
            cin >> S >> R;
            if(S > R)
            {
                points += 3;
            }
            else
            {
                ara[k] = R - S + 1;
                k++;
            }
        }
        sort (ara, ara+k);
        for (i=0; i<k; i++)
        {
            if((G-ara[i]) >= 0)
            {
                G -= ara[i];
                points += 3;
            }
            else if( (ara[i] - G) == 1)
            {
                points++;
                break;
            }
            else
            {
                break;
            }
        }
        for(j = i+1; j < k; j++)
        {
            if(ara[j] == 1)
            {
                points++;
            }
            else
            {
                break;
            }
        }
        cout << points << endl;
    }
}
