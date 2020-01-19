#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1009 ;
#define mid (l+r>>1)
ll st[N][N*4*2];
ll st1[2][100009*4];
ll lazy1[2][100009*4];
ll lazy[N][N*4*2];
int n;
void push1(int l,int r,int node,int m)
{
    if(lazy1[node][m])
    {
        st1[node][m]+=(r-l+1)*lazy1[node][m];
        if(l<r)
        {
            lazy1[node][m<<1]+=lazy1[node][m];
            lazy1[node][m<<1|1]+=lazy1[node][m];
        }
        lazy1[node][m]=0;
    }
}
void update1(int l,int r,int x,int y,int node,int m)
{
    push1(l,r,node,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        st1[node][m]+=r-l+1;
        if(l<r)
        {
            lazy1[node][m<<1]++;
            lazy1[node][m<<1|1]++;
        }
        return ;
    }
    update1(l,mid,x,y,node,m<<1);
    update1(mid+1,r,x,y,node,m<<1|1);
    st1[node][m]=st1[node][m<<1]+st1[node][m<<1|1];
}
ll findsum1(int l,int r,int x,int y,int node,int m)
{
    push1(l,r,node,m);
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st1[node][m];
    return findsum1(l,mid,x,y,node,m<<1)+findsum1(mid+1,r,x,y,node,m<<1|1);
}
void push(int l,int r,int node,int m)
{
    if(lazy[node][m])
    {
        st[node][m]+=(r-l+1)*lazy[node][m];
        if(l<r)
        {
            lazy[node][m<<1]+=lazy[node][m];
            lazy[node][m<<1|1]+=lazy[node][m];
        }
        lazy[node][m]=0;
    }
}
void update(int l,int r,int x,int y,int node,int m)
{
    push(l,r,node,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        st[node][m]+=r-l+1;
        if(l<r)
        {
            lazy[node][m<<1]++;
            lazy[node][m<<1|1]++;
        }
        return ;
    }
    update(l,mid,x,y,node,m<<1);
    update(mid+1,r,x,y,node,m<<1|1);
    st[node][m]=st[node][m<<1]+st[node][m<<1|1];
}
ll findsum(int l,int r,int x,int y,int node,int m)
{
    push(l,r,node,m);
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[node][m];
    return findsum(l,mid,x,y,node,m<<1)+findsum(mid+1,r,x,y,node,m<<1|1);
}
void rd(int x,int y)///rain drops
{
    for(;x<=n;x+=x&-x)update(1,n,1,y,x,1);
}
ll getsum(int x,int y1,int y2)
{
    ll sum=0 ;
    for(;x>0;x-=x&-x)sum+=findsum(1,n,y1,y2,x,1);
    return sum ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,q1,q2,u,v,x1,x2,y1,y2,type,b=0 ;
    cin >> q1 >> q2 >> n >> m ;
    q1+=q2;
    if(m>1000)b=1;
    if(!b)n=1001;
    else n = 100001;
    while(q1--)
    {
        cin >> type ;
        if(type==1)
        {
            cin >> u >> v ;
            u++,v++;
            if(b)update1(1,n,u,v,1,1);
            else rd(u,v);
        }
        else
        {
            cin >> x1 >> y1 >> x2 >> y2 ;
            x1++,y1++,x2++,y2++ ;
            y1++;
            if(b)cout << findsum1(1,n,y1,y2,1,1) << '\n' ;
            else cout << getsum(x2,y1,y2)-getsum(x1-1,y1,y2) << '\n' ;
        }
    }
}
