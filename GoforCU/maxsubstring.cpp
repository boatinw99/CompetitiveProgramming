#include<bits/stdc++.h>
using namespace std ;
vector<int>v[26];
vector<int>::iterator it;
string s;
int T(int q)
{
    int i,j,l,r ;
    if(v[q].size()==1)
    {
        return 1;
    }
    l=*v[q].begin();
    r=*(v[q].begin()+1);
    for(i=1;l+i<r;i++)
    {
        for(it=v[q].begin()+1;it!=v[q].end();it++)
        {
            if(*it+i>s.length())
            {
                return i;
            }
            if(s[*it+i-1]!=s[l+i-1])
            {
                return i ;
            }
        }
    }
    return i ;
}
main()
{
    int i,j,x,y,k ;
    int max1=1,p=0,pr=0 ;
    cin >> s;
    for(i=0;i<s.length();i++)
    {
        v[s[i]-'a'].push_back(i+1);
    }
    for(i=0;i<26;i++)
    {
        if(v[i].size()>=max1)
        {
            x=T(i);
            if(v[i].size()>max1)
            {
                max1=v[i].size();
                p=i;
                pr=x;
            }
            if(max1==v[i].size()&&x>pr)
            {
                pr=x;
                p=i;
            }
        }
    }
    if(max1==1)
    {
        cout << s;
        return 0 ;
    }
    for(i=0;i<pr;i++)
    {
        printf("%c",s[*v[p].begin()-1+i]);
    }
}
