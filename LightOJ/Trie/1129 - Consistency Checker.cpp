#include<bits/stdc++.h>
using namespace std;
bool res;
struct node
{
    bool endmark;
    node *next[10];
    int cnt;
    node()
    {
        endmark = false;
        for(int i=0; i<10; i++) next[i] = NULL;
    }
}*root;

void insert(char *str,int len)
{
    node *curr=root;
    bool flag = 1;
    for(int i=0; i<len; i++)
    {
        int id = str[i]-'0';
        if(curr-> next[id]==NULL)
        {
            flag = 0;
            curr -> next[id] = new node();
        }
        if(curr->endmark) res = 0;
        curr = curr->next[id];
    }
    curr->endmark=1;
    if(curr->endmark && flag) res = 0;
}
void del(node *cur)
{
    for(int i=0; i<10; i++) if(cur->next[i])
        del(cur->next[i]) ;
    free(cur) ;
}

int main()
{
    int TC, ind = 0;
    cin >> TC;
    while(TC--){
        root=new node();
        int num_word;
        cin>>num_word;
        res = 1;
        for(int i=1; i<=num_word; i++)
        {
            char str[11];
            scanf("%s",str);
            insert(str,strlen(str));
        }
        if(res) printf("Case %d: YES\n",++ind);
        else printf("Case %d: NO\n",++ind);
        del(root);
    }
    return 0;
}
