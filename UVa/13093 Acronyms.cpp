    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        freopen("i.txt","r",stdin);
        freopen("o.txt","w",stdout);
        int i,len1,len2;
        string s1,s2,s3,s4;
        while(getline(cin,s1)){
        getline(cin,s2);
        len1 = s1.length();
        len2 = s2.length();
        while(s1[0] == ' '){ s1.erase(0,1);}
        while(s2[0] == ' '){ s2.erase(0,1);}
        while(s1[len1-1] ==' ') {s1.erase(len1-1,1);len1--;}
        while(s2[len2-1] ==' ') {s2.erase(len2-1,1);len2--;}
        s3.push_back(s1[0]);
        s4.push_back(s2[0]);
        //cout << s1 << "**";
        //cout << s2 << "**";
        for(i=1;i<s1.length();i++)
        {
            if((s1[i] >= 'a' && s1[i] <= 'z') && s1[i-1] ==' ')
            {
                s3.push_back(s1[i]);
            }
        }
        for(i=1;i<s2.length();i++)
        {
            if((s2[i] >= 'a' && s2[i] <= 'z') && s2[i-1] ==' ')
            {
                s4.push_back(s2[i]);
            }
        }

        if(s3 == s4){ printf("yes\n");}
        else{ printf("no\n");}
    }
    }
