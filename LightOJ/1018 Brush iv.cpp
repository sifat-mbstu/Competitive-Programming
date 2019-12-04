
    ///   |----------------------------|
    ///   | BISMILLAHIR RAHMANIR RAHIM |
    ///   |----------------------------|

    ///       _______  __   ________   ___   .___________.
    ///      /       ||  | |   ____|  /   \  |           |
    ///     |   (----'|  | |  |__    /  ^  \ `---|  |----`
    ///      \   \    |  | |   __|  /  /_\  \    |  |
    ///  |----)   |   |  | |  |    /  _____  \   |  |
    ///  |_______/    |__| |__|   /__/     \__\  |__|
    ///
    ///**********************************************************//
    #include<bits/stdc++.h>
    using namespace std;

    #define   ff   first
    #define   ss   second
    #define   pb   push_back
    #define   mp   make_pair

    #define   SQ(n)         (n*n)
    #define   ll            long long
    #define   llu           unsigned long long

    #define   pi            acos(-1.0)

    #define   all(a)        a.begin(),a.end()
    #define   _max(a,b,c)   Max(a,Max(b,c))
    #define   _min(a,b,c)   Min(a,Min(b,c))

    #define   FOR(i,a,b)    for(int i=a;i<b; i++)

    #define   MEM(a,val)    memset(a,val,sizeof(a))

    #define   sf(a)         scanf("%d",&a)
    #define   sf2(a,b)      scanf("%d%d",&a,&b)
    #define   sf3(a,b,c)    scanf("%d%d%d",&a,&b,&c)
    #define   sf4(a,b,c,d)  scanf("%d%d%d%d",&a,&b,&c,&d)

    #define   sfl(a)        scanf("%lld",&a)
    #define   sfl2(a,b)     scanf("%lld%lld",&a,&b)
    #define   sfl3(a,b,c)   scanf("%lld%lld%lld",&a,&b,&c)
    #define   sfl4(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)

    #define   pnl()         printf("\n")

    #define   pf(a)         printf("%d",a)
    #define   pf2(a,b)      printf("%d %d",a,b)
    #define   pf3(a,b,c)    printf("%d %d %d",a,b,c)
    #define   pf4(a,b,c,d)  printf("%d %d %d %d",a,b,c,d)

    #define   pfl(a)        printf("%lld",a)
    #define   pfl2(a,b)     printf("%lld %lld",a,b)
    #define   pfl3(a,b,c)   printf("%lld %lld %lld",a,b,c)
    #define   pfl4(a,b,c,d) printf("%lld %lld %lld %lld",a,b,c,d)

    #define   tover(QLOW, QHIGH, LOW, HIGH)   QLOW<=LOW && QHIGH>= HIGH
    #define   nover(QLOW, QHIGH, LOW, HIGH)   QLOW>HIGH || QHIGH<LOW

    #define   bitCheck(a,k)  ((bool)(a&(1<<(k))))
    #define   bitOff(a,k)    (a&(~(1<<(k))))
    #define   bitOn(a,k)     (a|(1<<(k)))
    #define   bitFlip(a,k)   (a^(1<<(k)))

    #define   POPCOUNT       __builtin_popcount
    #define   POPCOUNTLL     __builtin_popcount
    #define   RIGHTMOST      __builtin_ctzll
    #define   LEFTMOST(x)    (63-__builtin_clzll((x)))

    #define   pii      pair<int,int>
    #define   pll      pair<ll,ll>
    #define   vi       vector<int>
    #define   vll       vector<ll>
    #define   FI       freopen("in.txt", "r", stdin)
    #define   FO       freopen("out.txt", "w", stdout)
    #define   MOD      1000000007
    #define   inf      111111111

    int fx[] = {1, -1, 0, 0};
    int fy[] = {0, 0, 1, -1};

    #define   fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
    int xi[32],yi[32];
    int dp[75536];
    int his[32][32];
    int n;
    double dhal(int i, int j)
    {
        double lob = yi[i] - yi[j];
        double hor = xi[i] - xi[j];
        double slope = lob/hor;
        return slope;
    }
    void precalc()
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(his[i][j]!=0)
                    continue;
                if(i==j)
                    continue;
                double cslope = dhal(i,j);
                int cmsk = 0;
                cmsk = bitOn(cmsk,i);
                for(int k=0; k<n; k++)
                {
                    if(dhal(i,k)==cslope)
                    {
                        cmsk = bitOn(cmsk,k);
                    }
                }
                for(int k=0; k<n; k++)
                {
                    if(dhal(i,k)==cslope)
                    {
    //                    pf3(i,k,cmsk);
                        his[i][k] = cmsk;
                        his[k][i] = cmsk;
                    }
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            his[i][i] = bitOn(0,i);
        }
    }
    int fun(int mask)
    {
        int x = POPCOUNT(mask);
        if(x==n)
            return 0;
        if(n-x<=2)
            return 1;
        int &Min = dp[mask];
        if(Min!=-1)
            return Min;
        Min = inf;
        int nai;
        for(int i=0; i<n; i++)
        {
            if(bitCheck(mask,i)==0)
            {
                nai = i;
                break;
            }
        }
        for(int j=nai+1; j<n; j++)
        {
            if(bitCheck(mask,j)!=0) continue;
            int nmsk2 = his[nai][j] | mask;
            Min = min(Min, 1+fun(nmsk2));
        }

        return Min;
    }
    int main()
    {
        int tc,idx=0;
        sf(tc);
        while(tc--)
        {
            MEM(dp,-1);
            MEM(his,0);
            sf(n);
            for(int i=0; i<n; i++)
            {
                sf2(xi[i],yi[i]);
            }
            precalc();
            int res = fun(0);
            printf("Case %d: %d\n",++idx,res);
        }
    }
