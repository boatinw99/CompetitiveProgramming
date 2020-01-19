/**
 *    Author : boatinw99
 *    Date : 2.5.2019 8:40 - 9:38
 */
#include "messy.h"
#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
string s = "" ;
vector<int> ans ;
void mem(int l,int r,char val)
{
    for(int i=l;i<=r;i++)s[i]=val;
}
void add(int l,int r)
{
    if(l+1==r)return ;
    int len = r-l+1>>1;
    mem(l,mid,'1');
    for(int i=mid+1;i<=mid+len/2;i++)
    {
        s[i]='1';
        add_element(s);
        //cout << s << '\n' ;
        s[i]='0';
    }
    mem(l,mid,'0');
    /// right side
    mem(mid+1,r,'1');
    for(int i=mid-len/2+1;i<=mid;i++)
    {
        s[i]='1';
        add_element(s);
        //cout << s << '\n' ;
        s[i]='0';
    }
    mem(mid+1,r,'0');
    add(l,mid);
    add(mid+1,r);
}
void solve(int l,int r,vector<int> &vl,vector<int> &vr)
{
    if(l+1==r)
    {
        ans.push_back(*vl.begin());
        ans.push_back(*vr.begin());
        return ;
    }
    vector<int> dl,dr ;
    //for(auto it:vl)printf("vl %d \n",it);
    //for(auto it:vr)printf("vr %d \n",it);
    for(auto it:vr)s[it]='1';
    for(auto it:vl)
    {
        s[it]='1';
        bool chk = check_element(s);
        if(chk)dr.emplace_back(it);
        else dl.emplace_back(it);
        s[it]='0';
    }
    for(auto it:vr)s[it]='0';
    solve(l,mid,dl,dr);
    dl.clear();
    dr.clear();
    ///right side
    for(auto it:vl)s[it]='1';
    for(auto it:vr)
    {
        s[it]='1';
        bool chk = check_element(s);
        if(chk)dl.emplace_back(it);
        else dr.emplace_back(it);
        s[it]='0';
    }
    for(auto it:vl)s[it]='0';
    solve(mid+1,r,dl,dr);
}
vector<int> restore_permutation(int n,int w,int r)
{
    vector<int> ret(n);
    for(int i=0;i<n;i++)s+="0";
    for(int i=0;i<n/2;i++)
    {
        s[i]='1';
        add_element(s);
        s[i]='0';
    }
    add(0,n-1);
    compile_set();
    vector<int> vl,vr;
    for(int i=0;i<n;i++)
    {
        s[i]='1';
        bool chk = check_element(s);
        if(chk)vl.push_back(i);
        else vr.push_back(i);
        s[i]='0';
    }
    solve(0,n-1,vl,vr);
    int idx = 0 ;
    for(auto it:ans)ret[it]=idx++;
    return ret ;
}
