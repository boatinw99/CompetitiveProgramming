#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
#define mid (l+r>>1)
#define fi first
#define se second
const ll inf = 1e9 ;
const int N = 1e5+9 ;
ll st[N<<2],lazy[N<<2];
ll a[N],b[N];
vector<ll> qwe ;
vector<pair<pll,int> > A ;
int pos[N];
void push(int l,int r,int m)
{
    if(lazy[m])
    {
        st[m]-=lazy[m];
        if(l<r)
        {
            lazy[m<<1]+=lazy[m];
            lazy[m<<1|1]+=lazy[m];
        }
        lazy[m]=0;
    }
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=a[l]+b[l];
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=max(st[m<<1],st[m<<1|1]);
}
void update(int l,int r,int x,int y,ll cst,int m)
{
    push(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        st[m]-=cst;
        if(l<r)
        {
            lazy[m<<1]+=cst;
            lazy[m<<1|1]+=cst;
        }
        return ;
    }
    update(l,mid,x,y,cst,m<<1);
    update(mid+1,r,x,y,cst,m<<1|1);
    st[m]=max(st[m<<1],st[m<<1|1]);
}
bool cmp(pair<pll,int> ls,pair<pll,int> rs)
{
    return ls.fi.se>rs.fi.se ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    ll ans = 0 ;
    int n,T ;
    ll u,v ;
    ll m1,m2 ;
    cin >> n >> T >> m1 >> m2 ;
    for(int i=1;i<=n;i++)
    {
        cin >> u >> v ;
        A.push_back({{u,v},i});
    }
    sort(A.begin(),A.end(),cmp);
    for(int i=0;i<n;i++)
    {
        pos[A[i].se]=i;
        a[i]=A[i].fi.fi;
        b[i]=A[i].fi.se;
        if(i>0)a[i]+=a[i-1];
    }
    construct(0,n-1,1);
    for(int i=n;i>=1;i--)
    {
        qwe.push_back(st[1]);
        update(0,n-1,pos[i],n-1,A[pos[i]].fi.fi,1);
        update(0,n-1,pos[i],pos[i],inf,1);
        //printf("aa chk %d %d\n",pos[i]);
    }
    for(int i=n-1;i>=0;i--)cout << qwe[i] << '\n' ;
}

