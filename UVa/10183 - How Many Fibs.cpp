#include<bits/stdc++.h>
using namespace std;
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
vector<string> vt;
bool comp(string s1,string s2)
{
    int len1=s1.size();
    int len2=s2.size();

    if(len1>len2)return true;
    else if(len2>len1) return false;
    for(int i=0; i<len1; i++)
    {
        if(s1[i]>s2[i]) return true;
        else if(s2[i]>s1[i]) return false;
    }
    return false;
}
string sum(string s1, string s2)
{
    string ss;
    int len1=s1.size();
    int len2=s2.size();
    if(len1>len2)
    {
        while(s1.size()>s2.size())
        {
            s2.insert(s2.begin(),'0');
        }
    }
    else  if(len2>len1)
    {
        while(s2.size()>s1.size())
        {
            s1.insert(s1.begin(),'0');
        }
    }
    len1=s1.size();
    int mod=0;
    for(int i=len1-1; i>=0; i--)
    {
        int a=(s1[i]-'0')+(s2[i]-'0')+mod;
        mod=a/10;
        a=a%10;
        ss+=(a+'0');
    }
    if(mod!=0)
    {
        ss+=mod+'0';
    }
    reverse(ss.begin(),ss.end());
    while(ss[0]=='0')
    {
        ss.erase(ss.begin());
    }
    return ss;
}
void fun()
{
    int i=2;
    vt.push_back("1");
    vt.push_back("1");
    while(i!=510)
    {
        string SS =sum(vt[i-1],vt[i-2]);
        vt.push_back(SS);
        i++;
    }
}
int main()
{
    fun();
    string st1,st2;
    while(cin>>st1>>st2)
    {
        if(st1=="0" && st2=="0")break;
        int ind1, ind2;
        for(int i=1; i<=508; i++)
        {
            if(st1 == vt[i])
            {
                ind1 = i;
                break;
            }
            if(comp(vt[i],st1))
            {
                ind1 = i;
                break;
            }
        }
        for(int i=1; i<=508; i++)
        {
            if(vt[i]==st2)
            {
                ind2 = i+1;
                break;
            }
            if(comp(vt[i],st2))
            {
                ind2 = i;
                break;
            }
        }
        cout << ind2-ind1 << endl;
    }
}
