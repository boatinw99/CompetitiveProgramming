#include "gap.h"
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll inf = 1e18 ;
vector<ll> v ;
void push(ll cst)
{
    if(cst>-1)v.emplace_back(cst);
}
ll findGap(int T, int N)
{
    ll mn=0,mx=0,l=0,r=inf ;
    v.clear();
    if(T==1)
    {
        for(int i=1;i<=(N+1)/2;i++)
        {
            MinMax(l,r,&mn,&mx);
            push(mn),push(mx);
            l=mn+1,r=mx-1;
        }
        sort(v.begin(),v.end());
        ll ret = 0 ;
        for(int i=1;i<(int)v.size();i++)ret=max(ret,v[i]-v[i-1]);
        return ret ;
    }
    else
    {
        ll ret = 0 ;
        MinMax(l,r,&mn,&mx);
        l=mn,r=mx;
        ll R = r ;
        ll len = (mx-mn)/(N)+1;
        ll ex = l;
        l=l+1;
        r=l+len;
        for(int i=1;l<=R&&i<=N;i++)
        {
            MinMax(l,r,&mn,&mx);
            if(mn!=-1)
            {
                ret = max(ret,mn-ex);
                ex = mx ;
            }
            l=r+1;
            r+=len;
        }
        return ret ;
    }
}
