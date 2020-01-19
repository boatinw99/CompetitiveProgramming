/**
 *    Author : boatinw99
 *    Date : 1.5.2019 11:54 - 12:21
**/
#include "combo.h"
#include<bits/stdc++.h>
using namespace std ;
set<char> s ;
char c[3];
string guess_sequence(int n)
{
    string ans = "" ;
    string p="AB";
    int ret = press(p);
    char root ;
    if(ret>=1)
    {
        p="A";
        ret = press(p);
        if(ret==1)root='A';
        else root='B';
    }
    else
    {
        p="X";
        ret = press(p);
        if(ret==1)root='X';
        else root='Y';
    }
    s.clear();
    s.insert('A');s.insert('B');s.insert('X');s.insert('Y');
    ans=root;
    s.erase(root);
    if(n==1)
    {
        return ans ;
    }
    int i = 0 ;
    for(auto it:s)c[i++]=it;
    //printf("chk %c %c %c \n",c[0],c[1],c[2]);
    for(int i=2;i<=n-1;i++)
    {
        p=ans+c[0]+c[0]+ans+c[0]+c[1]+ans+c[0]+c[2]+ans+c[1];
        int ret = press(p);
        if(ret==i+1)ans+=c[0];
        else if(ret==i)ans+=c[1];
        else ans+=c[2];
    }
    p = ans+c[0];
    ret = press(p);
    if(ret==n)
    {
        ret = press(p);
        if(ret==n)ans+=c[0];
    }
    else
    {
        ret=press(ans+c[1]);
        if(ret==n)ans+=c[1];
        else ans+=c[2];
    }
    return ans ;
}
