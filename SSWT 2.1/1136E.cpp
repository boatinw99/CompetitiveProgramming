#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define mid (l+r>>1)
#define fi first
#define se second
const ll MAX = 1e14 ;
const int N = 2e5+9 ;
ll a[N],k[N],t[N],b[N],qst[N],st[N<<2],lazy[N<<2],mx[N<<2];
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=mx[m]=b[l];
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=st[m<<1]+st[m<<1|1];
    mx[m]=max(mx[m<<1],mx[m<<1|1]);
}
void updlazy(int l,int r,int m)
{
    if(lazy[m]>-MAX)
    {
        st[m]=lazy[m]*(r-l+1);
        mx[m]=lazy[m];
        if(l<r)
        {
            lazy[m<<1]=lazy[m];
            lazy[m<<1|1]=lazy[m];
        }
        lazy[m]=-MAX ;
    }
}
void update(int l,int r,int x,int y,ll cst,int m)
{
    updlazy(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        st[m]=cst*(r-l+1);
        mx[m]=cst;
        if(l<r)
        {
            lazy[m<<1]=cst;
            lazy[m<<1|1]=cst;
        }
        return ;
    }
    update(l,mid,x,y,cst,m<<1);
    update(mid+1,r,x,y,cst,m<<1|1);
    st[m]=st[m<<1]+st[m<<1|1];
    mx[m]=max(mx[m<<1],mx[m<<1|1]);
}
ll getsum(int l,int r,int x,int y,int m)
{
    updlazy(l,r,m);
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    return getsum(l,mid,x,y,m<<1)+getsum(mid+1,r,x,y,m<<1|1);
}
int walk(int l,int r,ll cst,int m)
{
    updlazy(l,r,m);
    if(l==r)return l ;
    updlazy(l,mid,m<<1),updlazy(mid+1,r,m<<1|1);
    if(mx[m<<1]>=cst)return walk(l,mid,cst,m<<1);
    else return walk(mid+1,r,cst,m<<1|1);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,m,u,v ;
    cin >> n ;
    for(i=1;i<=n;i++)cin >> a[i] ;
    for(i=1;i<n;i++)cin >> k[i] ;
    fill(lazy,lazy+N*4-1,-MAX);
    for(i=1;i<=n;i++)
    {
        t[i]=k[i-1]+t[i-1];
        qst[i]=t[i]+qst[i-1];
        b[i]=a[i]-t[i];
    }
    n++;
    b[n]=-MAX ;
    construct(1,n,1);
    cin >> m ;
    while(m--)
    {
        char c ;
        cin >> c ;
        if(c=='s')
        {
            cin >> u >> v ;
            cout << getsum(1,n,u,v,1)+qst[v]-qst[u-1] << '\n' ;
        }
        else
        {
            cin >> u >> v ;
            ll ret = getsum(1,n,u,u,1)+v;
            int R = walk(1,n,ret,1);
            R=max(R,u+1);
            update(1,n,u,R-1,ret,1);
           // printf("aaaaaa %d %d %d\n",u,R-1,v);
        }
    }
}
