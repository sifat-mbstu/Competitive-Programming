#include<bits/stdc++.h>
using namespace std;
#define MPSI map<string, int>
#define inf INT_MAX/3
char stt[100000+9];
int main()
{
    int ind = 0;
    int TC;
    scanf("%d",&TC);
    while(TC--)
    {
        char st[1000];
        MPSI MAP;
        int num_word;
        scanf("%d",&num_word);
        getchar();
        for(int i=1; i<=num_word; i++)
        {
            scanf("%s",st);
            int ss = strlen(st);
            string s (st,st+ss);
            if(s.size() > 3)
                sort(s.begin()+1,s.end()-1);
            MAP[s]++;
        }
        
        int q;
        printf("Case %d:\n",++ind);
        scanf("%d",&q);
        getchar();
        while(q--)
        {
            int multi = 1;
            gets(stt);
            int l = strlen(stt);
            string str(stt,stt+l);
            stringstream ss;
            ss<<str;
            while(ss>>str){
                if(str.size() > 3)
                    sort(str.begin()+1,str.end()-1);
                
                multi *= MAP[str];
            }
            printf("%d\n",multi);
        }
    }
    return 0;
}
