#include<bits/stdc++.h>
using namespace std;
int k,n, a[10010];
int find_dir(int Mid)
{
    int t=0;
    for(int i=0; i<n; i++)
    {
        int sum = a[i];
        while(sum <= Mid)
        {
            sum += a[i+1];
            if(sum > Mid)
            {
                break;
            }
            i++;
        }
        t++;
    }
    if(t>k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int binary(int BEG, int END)
{
    int MID, MID1;
    int t=0;
    while(BEG <= END)
    {
        MID = (BEG+END)/2;
        //printf("Mid = %d\n",MID);
        //cout << "DIR  "  << find_dir(MID) << endl;

        if(find_dir(MID)==1)
        {
            BEG = MID+1;
        }
        else
        {
            END = MID-1;
            MID1 = MID;
        }
    }
    return MID1;
}
int main()
{
    int TC, Case= 0;
    cin >> TC;
    while(TC--)
    {
        scanf("%d %d",&n,&k);
        k++;
        n++;
        int MAX = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            MAX = max(MAX, a[i]);
        }
        int Mid = binary(MAX, MAX*n);
        printf("Case %d: %d\n",++Case,Mid);
        for(int i=0; i<n; i++)
        {
            int sum = a[i];
            while(sum < Mid)
            {
                if((sum+a[i+1]) > Mid || (i+1) == n || (n-i) <= k)
                {
                    break;
                }
                sum += a[i+1];
                i++;
            }
            printf("%d\n",sum);
            k--;
        }
    }
}
