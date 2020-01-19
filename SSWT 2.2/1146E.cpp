#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 2e5+9 , ad = 1e5+1 , M = 2e5+4 ;
pii st[N<<2];
priority_queue<pii> pq ;
int n,m,a[N],q[N],start[N];
char s[N];
pii operate1(pii a,pii b)
{
    return {max(a.fi,b.fi),max(a.se,b.se)};
}
pii operate2(pii a,pii b)
{
    return {a.fi+b.fi,a.se+b.se};
}
void update1(int l,int r,int x,pii y,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m]=operate1(st[m],y);
        return ;
    }
    update1(l,mid,x,y,m<<1);
    update1(mid+1,r,x,y,m<<1|1);
    st[m]=operate1(st[m<<1],st[m<<1|1]);
}
void update2(int l,int r,int x,pii y,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m]=operate2(st[m],y);
        return ;
    }
    update2(l,mid,x,y,m<<1);
    update2(mid+1,r,x,y,m<<1|1);
    st[m]=operate2(st[m<<1],st[m<<1|1]);
}
pii getmax(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return {0,0} ;
    if(l>=x&&r<=y)return st[m] ;
    return operate1(getmax(l,mid,x,y,m<<1),getmax(mid+1,r,x,y,m<<1|1));
}
pii getsum(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return {0,0} ;
    if(l>=x&&r<=y)return st[m];
    return operate2(getsum(l,mid,x,y,m<<1),getsum(mid+1,r,x,y,m<<1|1));
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ;
    for(int i=1;i<=n;i++)cin >> a[i] ;
    for(int i=1;i<=m;i++)
    {
        cin >> s[i] >> q[i];
        if(s[i]=='<')update1(1,M,q[i]+ad,{i,0},1);
        else update1(1,M,q[i]+ad,{0,i},1);
    }
    for(int i=1;i<=n;i++)
    {
        int tmpL = getmax(1,M,-abs(a[i])+ad+1,abs(a[i])+ad,1).fi ;
        int tmpR = getmax(1,M,-abs(a[i])+ad,abs(a[i])+ad-1,1).se ;
        start[i]=max(tmpL,tmpR);
        if(start[i])a[i]=(s[start[i]]=='<'?abs(a[i]):-abs(a[i]));
        pq.push({start[i],i});
    }
    for(int i=0;i<N*4;i++)st[i]={0,0};
    int exidx = m+1 ;
    while(!pq.empty())
    {
        pii x = pq.top(); pq.pop();
        //printf("query %d %d | ",x.fi,x.se);
        while(exidx>x.fi+1)
        {
            exidx--;
            /// < , >
            if(s[exidx]=='<')update2(1,M,ad+q[exidx],{1,0},1);
            else update2(1,M,ad+q[exidx],{0,1},1);
        }
        int sum = getsum(1,M,abs(a[x.se])+ad,M,1).fi+
            getsum(1,M,1,-abs(a[x.se])+ad,1).se;
        //printf("%d \n",sum);
        if(sum&1)a[x.se]*=-1;
    }
    for(int i=1;i<=n;i++)cout << a[i] << " " ;
}
