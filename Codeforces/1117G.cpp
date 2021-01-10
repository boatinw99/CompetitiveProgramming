#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e6+9 ;
#define mid (l+r>>1)
struct p
{
    int lft,rht,id ;
}q[N];
bool cmp(p lhs,p rhs)
{
    return lhs.rht < rhs.rht ;
}
ll st[N<<2],lazy[N<<2],ans[N];
int a[N],L[N],R[N],n,m;
void updlazy(int l,int r,int m)
{
    if(lazy[m])
    {
        st[m]+=(r-l+1)*lazy[m];
        if(l<r)
        {
            lazy[m<<1]+=lazy[m];
            lazy[m<<1|1]+=lazy[m];
        }
        lazy[m]=0;
    }
}
void update(int l,int r,int x,int y,int m)
{
    updlazy(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        st[m]+=r-l+1;
        if(l<r)
        {
            lazy[m<<1]++;
            lazy[m<<1|1]++;
        }
        return ;
    }
    update(l,mid,x,y,m<<1);
    update(mid+1,r,x,y,m<<1|1);
    st[m]=st[m<<1]+st[m<<1|1];
}
ll getsum(int l,int r,int x,int y,int m)
{
    updlazy(l,r,m);
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m] ;
    return getsum(l,mid,x,y,m<<1)+getsum(mid+1,r,x,y,m<<1|1);
}
void query()
{
    stack<int> stk ;
    int i,j;
    sort(q+1,q+1+m,cmp);
    for(i=1;i<=n;i++)
    {
        while(!stk.empty()&&a[stk.top()]<a[i])stk.pop();
        if(stk.empty())L[i]=0 ;
        else L[i]=stk.top();
        stk.push(i);
    }
    for(i=1,j=1;i<=n;i++)
    {
        update(1,n,L[i]+1,i,1);
        while(j<=m&&q[j].rht==i)
            ans[q[j].id]+=getsum(1,n,q[j].lft,q[j].rht,1),j++;
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=m;i++)cin >> q[i].lft;
    for(i=1;i<=m;i++)cin >> q[i].rht;
    for(i=1;i<=m;i++)q[i].id=i ;
    query();
    reverse(a+1,a+1+n);
    memset(st,0,sizeof st);
    memset(lazy,0,sizeof lazy);
    for(i=1;i<=m;i++)ans[q[i].id]-=q[i].rht-q[i].lft+1;
    for(i=1;i<=m;i++)
    {
        q[i].lft=n-q[i].lft+1;
        q[i].rht=n-q[i].rht+1;
        swap(q[i].lft,q[i].rht);
    }
    query();
    for(i=1;i<=m;i++)cout << ans[i] << " " ;
}
