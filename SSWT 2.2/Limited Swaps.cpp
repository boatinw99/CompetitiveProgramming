#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define mid (l+r>>1)
const int N = 1e5+9 ;
int a[N];
struct node
{
    int val,pos,sum ;
};
node st[N<<2];
node operate(node a,node b)
{
    node ret ;
    if(a.val>=b.val)ret={a.val,a.pos,0};
    else ret={b.val,b.pos,0};
    ret.sum = a.sum+b.sum ;
    return ret ;
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]={a[l],l,1};
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
void update(int l,int r,int x,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m]={-1,x,0};
        return ;
    }
    update(l,mid,x,m<<1);
    update(mid+1,r,x,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
node getans(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return {0,0,0};
    if(l>=x&&r<=y)return st[m];
    return operate(getans(l,mid,x,y,m<<1),getans(mid+1,r,x,y,m<<1|1));
}
int getpos(int l,int r,int k,int m)
{
    if(l==r)return l ;
    if(st[m<<1].sum>=k)return getpos(l,mid,k,m<<1);
    else return getpos(mid+1,r,k-st[m<<1].sum,m<<1|1);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    ll k ;
    cin >> n >> k ;
    for(int i=1;i<=n;i++)cin >> a[i] ;
    construct(1,n+1,1);
    for(int i=1;i<=n;i++)
    {
        int pos = getpos(1,n+1,k+2,1);
        node ret = getans(1,n+1,1,pos-1,1);
        int sum = getans(1,n+1,1,ret.pos,1).sum;
        update(1,n+1,ret.pos,1);
        k-=sum-1;
        cout << ret.val << " " ;
    }
    return 0 ;
}
