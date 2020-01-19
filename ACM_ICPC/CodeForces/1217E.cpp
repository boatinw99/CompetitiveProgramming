#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
#define mid (l+r>>1)
const ll INF = 1e14 ; 
const int N = 2e5+9 ; 
int n,m ;
struct Tree
{
    ll digit[9];
    ll ans ; 
}st[N<<2],Tinf;
Tree operate(Tree a,Tree b)
{
    Tree t=Tinf ;
    t.ans=min(a.ans,b.ans);
    for(int i=0;i<9;i++) 
    {
        t.ans=min(t.ans,a.digit[i]+b.digit[i]);   
        t.digit[i]=min(a.digit[i],b.digit[i]);
    }
    return t ;
}
void update(int l,int r,int x,int nw,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m]=Tinf ; 
        int tmp = nw ; 
        int di = 0 ;
        while(nw>0)
        {
            if(nw%10)st[m].digit[di]=tmp ;
            nw/=10;
            di++;
        }
        return ;
    }
    update(l,mid,x,nw,m<<1);
    update(mid+1,r,x,nw,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
Tree getval(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return Tinf;
    if(l>=x&&r<=y) 
    {
        return st[m];
    }
    return operate(getval(l,mid,x,y,m<<1),getval(mid+1,r,x,y,m<<1|1));
}
ll getans(int x,int y)
{
    ll ret = getval(1,n,x,y,1).ans;
    return (ret>=2e9?-1:ret) ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ;
    for(int i=0;i<9;i++)Tinf.digit[i]=INF ;
    Tinf.ans=INF;
    for(int i=1,u ;i<=n;i++)
    {
        cin >> u ; 
        update(1,n,i,u,1);
    }
    for(int i=1,u,l,r ;i<=m;i++)
    {
        cin >> u >> l >> r; 
        if(u==1)
        {
            update(1,n,l,r,1);
        }
        else cout << getans(l,r) << '\n' ;
    }
    return 0 ;
}