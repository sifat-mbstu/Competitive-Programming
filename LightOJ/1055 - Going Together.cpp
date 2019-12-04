#include<bits/stdc++.h>
using namespace std;
#define mx 15
#define inf INT_MAX/3
#define fs first
#define sc second
#define pii pair<int,int>
#define mp make_pair
int fx[] = {0, 0,1,-1};
int fy[] = {1,-1,0, 0};
string s[mx];
int Min = inf;
pii DES[4];
int vis[mx][mx][mx];
int lev[11][11][11][11][11][11];
queue<pii>Q;
int row, col;
bool check(int x, int y)
{
    if(x>=0 && x<row && y>=0 && y<col && s[x][y]!='#')
    {
        return 1;
    }
    return 0;
}

bool reach_or_not(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if(s[x1][y1]=='X' && s[x2][y2]=='X' && s[x3][y3] =='X')
    {
        return 1;
    }
    return 0;
}

bool checking(int x1, int y1, int x2, int y2, int x3, int y3)
{
    pii p1= mp(x1,y1);
    pii p2= mp(x2,y2);
    pii p3= mp(x3,y3);
    if(p1 == p2)
    {
        return 1;
    }
    if(p1 == p3)
    {
        return 1;
    }
    if(p2 == p3)
    {
        return 1;
    }
    return 0;
}
void Bfs()
{
    bool AA, BB,CC;
    while(!Q.empty())
    {
        pii A_top = Q.front();
        Q.pop();
        pii B_top = Q.front();
        Q.pop();
        pii C_top = Q.front();
        Q.pop();
        for(int i=0; i<4; i++)
        {
            AA = 0;
            BB = 0;
            CC = 0;
//            printf("A_fs = %d __ A_sc = %d __ \nB_fs = %d __ B_sc = %d \nC_fs = %d __ C_sc = %d\n\n",A_top.fs,A_top.sc,B_top.fs,B_top.sc,C_top.fs,C_top.sc);
            int x1, y1, x2, y2,x3,y3;
            int A_tx = A_top.fs + fx[i];
            int A_ty = A_top.sc + fy[i];

            int B_tx = B_top.fs + fx[i];
            int B_ty = B_top.sc + fy[i];

            int C_tx = C_top.fs + fx[i];
            int C_ty = C_top.sc + fy[i];
            if(check(A_tx, A_ty) )//&& !(A_tx==B_top.fs && A_ty == B_top.sc) && !(A_tx==C_top.fs && A_ty == C_top.sc))
            {
                AA = 1;
            }

            if(check(B_tx, B_ty) ) //&& !(B_tx==x1 && B_ty == y1) && !(B_tx==C_top.fs && B_ty == C_top.sc) )
            {
                BB = 1;
            }

            if(check(C_tx, C_ty))// && !(C_tx==x2 && C_ty == y2) && !(C_tx==x1 && C_ty == y1))
            {
                CC  = 1;
            }
            x1 = x2 = x3 = y1 = y2 = y3 = -1;

            //&& (x1==-1 && y1 == -1)
            //&& (x2==-1 && y2 == -1)
            //&& (x3==-1 && y3 == -1)

            if(!AA && (x1==-1 && y1 == -1) )
            {
                x1 = A_top.fs;
                y1 = A_top.sc;
                if(BB)
                {
                    if(B_tx == x1 && B_ty == y1)
                    {
                        x2 = B_top.fs;
                        y2 = B_top.sc;
                        if(CC)
                        {
                            if(C_tx == x2 && C_ty == y2)
                            {
                                x3 = C_top.fs;
                                y3 = C_top.sc;
                            }
                        }
                    }
                }
                if(CC)
                {
                    if(C_tx == x1 && C_ty == y1)
                    {
                        x3 = C_top.fs;
                        y3 = C_top.sc;

                        if(BB)
                        {
                            if(B_tx == x3 && B_ty == y3)
                            {
                                x2 = B_top.fs;
                                y2 = B_top.sc;
                            }
                        }
                    }
                }
            }

            if(!BB)
            {
                x2 = B_top.fs;
                y2 = B_top.sc;
                if(AA)
                {
                    if(A_tx == x2 && A_ty == y2)
                    {
                        x1 = A_top.fs;
                        y1 = A_top.sc;
                        if(CC)
                        {
                            if(C_tx == x1 && C_ty == y1)
                            {
                                x3 = C_top.fs;
                                y3 = C_top.sc;
                            }
                        }
                    }
                }
                if(CC)
                {
                    if(C_tx == x2 && C_ty == y2)
                    {
                        x3 = C_top.fs;
                        y3 = C_top.sc;
                        if(AA)
                        {
                            if(A_tx == x3 && A_ty == y3)
                            {
                                x1 = A_top.fs;
                                y1 = A_top.sc;
                            }
                        }
                    }
                }
            }
//            if(A_top.fs == 0 && A_top.sc == 0 && B_top.fs == 0 && B_top.sc == 2 && C_top.fs == 0 && C_top.sc == 1)
//            {
//                printf("**************************************\n");
//                printf("AA = %d .. BB= %d .. CC== %d\n",AA,BB,CC);
//            }
            if(!CC)
            {
                x3 = C_top.fs;
                y3 = C_top.sc;
                if(AA)
                {
                    if(A_tx == x3 && A_ty == y3)
                    {
                        x1 = A_top.fs;
                        y1 = A_top.sc;
                        if(BB)
                        {
                            if(B_tx == x1 && B_ty == y1)
                            {
                                x2 = B_top.fs;
                                y2 = B_top.sc;
                            }
                        }
                    }
                }
                if(BB)
                {
                    if(B_tx == x3 && B_ty == y3)
                    {
                        x2 = B_top.fs;
                        y2 = B_top.sc;
                        if(AA)
                        {
                            if(A_tx == x2 && A_ty == y2)
                            {
                                x1 = A_top.fs;
                                y1 = A_top.sc;
                            }
                        }
                    }
                }
            }
            if(x1 == -1 && y1 == -1)
            {
                x1 = A_tx;
                y1 = A_ty;
            }
            if(x2 == -1 && y2 == -1)
            {
                x2 = B_tx;
                y2 = B_ty;
            }
            if(x3 == -1 && y3 == -1)
            {
                x3 = C_tx;
                y3 = C_ty;
            }

            if(lev[x1][y1][x2][y2][x3][y3]==inf)
            {

//                printf(" fx = %d fy = %d\n",fx[i], fy[i]);
//                printf(" x1 = %d y1 = %d\n",x1, y1);
//                printf(" x2 = %d y2 = %d\n",x2, y2);
//                printf(" x3 = %d y3 = %d\n",x3, y3);

                Q.push(mp(x1,y1));
                Q.push(mp(x2,y2));
                Q.push(mp(x3,y3));
                lev[x1][y1][x2][y2][x3][y3] = lev[A_top.fs][A_top.sc][B_top.fs][B_top.sc][C_top.fs][C_top.sc] + 1;

//                printf("lev = %d\n",lev[x1][y1][x2][y2][x3][y3]);
//                if(checking(x1,y1,x2,y2,x3,y3))
//                {
////                    cout << "YES====================================================\n";
//                }
//                getchar();


                if(reach_or_not(x1,y1,x2,y2,x3,y3))
                {
                    int Max = lev[x1][y1][x2][y2][x3][y3];
                    Min = min(Min, Max);
//                    cout <<"------------------------------>MIN = " << Min << endl;
                }
            }
//            int Max = 0;


        }
    }
}

int main()
{
    pii A_top;
    pii B_top;
    pii C_top;
//    freopen("out.txt","w",stdout);
    int TC;
    int ind = 0;
    cin >> TC;
    while(TC--)
    {
        Min = inf;
        for(int i=0; i<11; i++)
        {
            for(int j=0; j<11; j++)
            {
                for(int k=0; k<11; k++)
                {
                    for(int l=0; l<11; l++)
                    {
                        for(int m=0; m<11; m++)
                        {
                            for(int n=0; n<11; n++)
                            {
                                lev[i][j][k][l][m][n] = inf;
                            }
                        }
                    }

                }
            }
        }
        cin >> row;
        col = row;

        int IND = 0;
        int IND1 = 0;
        for(int i=0; i<row; i++)
        {
            cin >> s[i];
            for(int j=0; j<col; j++)
            {
                if(s[i][j]=='X')
                {
                    DES[IND++] = mp(i,j);
                }
                if(s[i][j]=='A' || s[i][j]=='B' || s[i][j]=='C')
                {
                    if(s[i][j]=='A') A_top = mp(i,j);
                    if(s[i][j]=='B') B_top = mp(i,j);
                    if(s[i][j]=='C') C_top = mp(i,j);
                }
            }
        }

        lev[A_top.fs][A_top.sc][B_top.fs][B_top.sc][C_top.fs][C_top.sc] = 0;
        Q.push(A_top);
        Q.push(B_top);
        Q.push(C_top);
        Bfs();

        if(Min == inf) printf("Case %d: trapped\n",++ind);
        else printf("Case %d: %d\n",++ind, Min);
//        cout << Min << endl;
    }
}
