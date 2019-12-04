#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,cpy,coco,MAX;
    while(scanf("%lld",&coco)==1){
    if(coco <0){break;}
    n = coco; MAX = 0;
    long long lim = sqrt(coco);
    bool solution = true;
    for(i=2; i<=lim*2; i++)
    {
        solution = true;
        n = coco;
        if(n%i==1)
        {
            cpy = i;
            while(cpy--)
            {
                //if(i==3)cout << cpy << "cpy" << endl;
                if(n%i ==1)
                {
                    n = ((n-1)*(i-1)) / i;
                }
                else{solution = 0;}
                //if(i==3) cout << n << endl<< endl;
            }
            if(n%i == 0 && solution == true)
            {
                MAX = max(MAX, i);
            }
        }
    }
    if(MAX != 0){printf("%lld coconuts, %lld people and 1 monkey\n",coco, MAX);}
    else {printf("%lld coconuts, no solution\n",coco);}
    }
}
