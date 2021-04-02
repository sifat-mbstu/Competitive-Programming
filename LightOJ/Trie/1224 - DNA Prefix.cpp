#include<bits/stdc++.h>
using namespace std;

struct node
{
    bool endmark;
    node *next[4];
    int cnt;
    node()
    {
        endmark = false;
        cnt = 0;
        for(int i=0; i<4; i++) next[i] = NULL;
    }
}*root;
int Max;

void insert(char *str,int len)
{
    node *curr = root;
    for(int i=0; i<len; i++)
    {
        int id;
        if(str[i] == 'A') id=0;
        else if(str[i] == 'C') id=1;
        else if(str[i] == 'G') id=2;
        else  if(str[i] == 'T') id=3;
        if(curr->next[id]==NULL)
        {
            curr -> next[id] = new node();
        }
        curr = curr->next[id];
        curr-> cnt++;
        int d = curr-> cnt;
        d = d * (i+1);
        Max = max(Max, d);
    }
    curr->endmark=1;
}
void del(node *cur)
{
    for(int i=0; i<4; i++) if(cur->next[i])
        del(cur->next[i]) ;
    delete(cur) ;
}

int main()
{
    int TC, ind=0;
    cin >> TC;
    while(TC--)
    {
        root=new node();
        int num_word;
        cin>>num_word;
        Max = 0;
        for(int i=1; i<=num_word; i++)
        {
            char str[500];
            scanf("%s",str);
            insert(str,strlen(str));
        }
        printf("Case %d: %d\n",++ind, Max);
        
        del(root);
    }
    return 0;
}

