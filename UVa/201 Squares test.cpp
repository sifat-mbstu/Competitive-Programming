///Accepted
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ppii pair<pii,pii>
int n,m;
map<ppii, int> Map;
int fx[] = { 0, 1 , 1};
int fy[] = { 1, 0 , 1};
bool check_if_exist(int x, int y, int len)
{
    int len1,len2;
    for(int k=0; k<2; k++)
    {
        bool exist = true;
        len1 = len2 = len;
        int x1 = x;
        int y1 = y;
        while(len1--)
        {
            pii P1 = make_pair(x1,y1);
            x1 += fx[k];
            y1 += fy[k];

            if(x1 >0 && x1 <= n && y1>0 && y1 <= n){

            /*if(x == 2 && y==2 && len == 3 ){
            getchar();
            printf("Hmmm1,,,, x1 = %d",x1);
            printf(" ,, y1 = %d\n",y1);
            }*/
            pii P2 = make_pair(x1,y1);
            ppii P = make_pair(P1,P2);
            if(Map[P] !=1){return 0;}
            }
            else{return 0;}
        }
    }
    x += fx[2]*len;
    y += fy[2]*len;
    for(int k=0; k<2; k++)
    {
        bool exist = true;
        len1 = len2 = len;
        int x1 = x;
        int y1 = y;
        while(len1--)
        {
            pii P1 = make_pair(x1,y1);
            x1 -= fx[k];
            y1 -= fy[k];

            if(x1 >0 && x1 <= n && y1>0 && y1 <= n){

            /*if(x == 4 && 4==2 && len == 3 ){
            getchar();
            printf("Hmmm2,,,, x1 = %d",x1);
            printf(" ,, y1 = %d\n",y1);
            }*/

            pii P2 = make_pair(x1,y1);
            ppii P = make_pair(P1,P2);
            if(Map[P] !=1){return 0;}
            }
            else{return 0;}
        }
    }
    return 1;
}
int main()
{
    int x = 0, f = 0;
    while(scanf("%d %d",&n,&m)==2){
    if(f){
        printf("\n**********************************\n\n");
    }
    char ch;
    int a,b,res[100];
    memset(res, 0, sizeof(res));
    Map.clear();
    bool exist = false;
    for(int i=0; i<m; i++)
    {
        getchar();
        scanf("%c%d%d",&ch,&a,&b);
        if(ch == 'H')
        {
            //printf("ch = %c\n",ch);
            ch = 'f';
            pii p1 = make_pair(a,b);
            pii p2 = make_pair(a,b+1);

            //printf("(x,y) = (%d %d)\n",a,b);
           // printf("(x1,y1) = (%d %d)\n",a,b+1);
            //getchar();

            Map[make_pair(p1,p2)] = 1;
            Map[make_pair(p2,p1)] = 1;

        }
        else{
            pii p1 = make_pair(b,a);
            pii p2 = make_pair(b+1,a);
            //printf("(x,y) = (%d %d)\n",b,a);
            //printf("(x1,y1) = (%d %d)\n",b+1,a);
            //getchar();
            Map[make_pair(p1,p2)] = 1;
            Map[make_pair(p2,p1)] = 1;
        }
    }
    int cnt = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=n; k++)
            {
                bool q = check_if_exist(i,j,k);
                if(q)
                {
                    /*getchar();
                    printf("----> i %d j %d k %d\n\n",i,j,k);
                    getchar();*/
                    res[k]++;
                    exist = 1;
                }
            }
        }
    }
    printf("Problem #%d\n\n",++x);
    if(exist){
        for(int i=1; i<=n; i++)
        {
            if(res[i]>0)
            {
                printf("%d square (s) of size %d\n",res[i],i);
            }
        }
    }
    else{printf("No completed squares can be found.\n");}
    f = 1;
    }
}
