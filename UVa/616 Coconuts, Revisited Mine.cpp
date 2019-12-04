#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,cpy,coco;
    bool t = 0;
    while(scanf("%lld",&coco)==1){
            t = 0;
    if(coco < 0){break;}
    n = coco;
    long long lim = sqrt(coco)+2;
    bool solution = true;
    for(i=lim; i>=2; i--)
    {
        solution = 1;
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
                t = 1;
                printf("%lld coconuts, %lld people and 1 monkey\n",coco, i);
                break;
            }
        }
    }

    if(!t) printf("%lld coconuts, no solution\n",coco);
    }
}
