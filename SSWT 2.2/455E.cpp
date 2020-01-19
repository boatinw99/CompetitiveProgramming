#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
#define fi first
#define se second
const ll inf = 1e18 ;
const int N = 1e5+9 ;
ll qs[N],a[N];
vector<pair<pll,int> > cc;
struct line
{
    ll m,c ;
    line(ll m,ll c):m(m),c(c){}
    ll f(ll x)
    {
        return m*x+c ;
    }
};
struct cht
{
    vector<line> l;
    bool bad(line a,line b,line c)
    {
        return 1.0*(c.c-a.c)/(a.m-c.m)>1.0*(b.c-a.c)/(a.m-b.m);
    }
    void add(line now)
    {
        if(!l.empty()&&l.back().m==now.m)l.pop_back();
        while(l.size()>1&&bad(l[l.size()-2],l.back(),now))l.pop_back();
        l.push_back(now);
    }
    ll query(ll x)
    {
        if(l.empty())return inf ;
        int L=0,R=l.size()-1;
        while(L<R)
        {
            int mid = L+R>>1;
            if(l[mid].f(x)<l[mid+1].f(x))R=mid;
            else L=mid+1 ;
        }
        return l[L].f(x);
    }

}st[N<<2];
void update(int l,int r,int x,line now,int m)
{
    if(r<x||l>x)return ;
    st[m].add(now);
    if(l==r)return ;
    int mid = l+r>>1 ;
    update(l,mid,x,now,m<<1);
    update(mid+1,r,x,now,m<<1|1);
}
ll findmin(int l,int r,int x,int y,ll p,int m)
{
    if(r<x||l>y)return inf ;
    if(l>=x&&r<=y)return st[m].query(p);
    int mid=l+r>>1;
    return min(findmin(l,mid,x,y,p,m<<1),findmin(mid+1,r,x,y,p,m<<1|1));
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,m;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i] ;
        qs[i]=a[i]+qs[i-1];
        cc.push_back({{a[i],a[i]*i-qs[i]},i});
    }
    sort(cc.begin(),cc.end(),greater<pair<pll,int> >());
    for(auto it:cc)update(1,n,it.se,line(-it.fi.fi,it.fi.se),1);
    cin >> m ;
    while(m--)
    {
        cin >> i >> j ;
        cout << findmin(1,n,1-i+j,j,j-i,1)+qs[j]<< '\n';
    }
}
