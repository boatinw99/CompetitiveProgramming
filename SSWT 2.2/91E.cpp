#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
#define fi first
#define se second
typedef long long ll ;
typedef pair<ll,int> pli ;
const ll inf = 1e18 ;
const int N = 1e5+9 ;
struct line
{
    ll m,c;
    int pos ;
    line (ll m,ll c,int pos):m(m),c(c),pos(pos){}
    ll f(ll x)
    {
        return m*x+c ;
    }
};
struct cht
{
    vector<line> L;
    bool bad(line a,line b,line c)
    {
       // printf("point a(%lld %lld) , b(%lld %lld) , c(%lld %lld) \n",
         //      a.m,a.c,b.m,b.c,c.m,c.c);
        return 1.0*(c.c-a.c)/(a.m-c.m)<=1.0*(b.c-a.c)/(a.m-b.m);
    }
    void add(line now)
    {
        if(!L.empty()&&L.back().m==now.m)L.pop_back();
        while(L.size()>1&&bad(L[L.size()-2],L.back(),now))L.pop_back();
        L.push_back(now);
    }
    pli query(ll x)
    {
        if(L.empty())return {-inf,0} ;
        int l=0,r=L.size()-1;
        while(l<r)
        {
            if(L[mid].f(x)>L[mid+1].f(x))r=mid ;
            else l=mid+1;
        }
        return {L[l].f(x),L[l].pos};
    }
    void print()
    {
        for(auto it:L)cout << it.m << " " << it.c << " " << it.pos << '\n' ;
    }

}st[N<<2];
vector<line> cc ;
void update(int l,int r,int x,line now,int m)
{
    if(r<x||l>x)return ;
    st[m].add(now);
    if(l==r)return ;
    update(l,mid,x,now,m<<1);
    update(mid+1,r,x,now,m<<1|1);
}
pli operate(pli a,pli b)
{
    if(a.fi>=b.fi)return a ;
    return b ;
}
pli getmax(int l,int r,int x,int y,int p,int m)
{
    if(r<x||l>y)return {-inf,0} ;
    if(l>=x&&r<=y)return st[m].query(p);
    return operate(getmax(l,mid,x,y,p,m<<1),getmax(mid+1,r,x,y,p,m<<1|1));
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,T,x,l,r ;
    ll m,c ;
    cin >> n >> T ;
    for(i=1;i<=n;i++)
    {
        cin >> c >> m ;
        cc.push_back(line(m,c,i));
    }
    sort(cc.begin(),cc.end(),[&](line a,line b)
         {
            if(a.m!=b.m)return a.m<b.m ;
            return a.c<b.c ;
         });
    for(auto it:cc)update(1,n,it.pos,it,1);
    while(T--)
    {
        cin >> l >> r >> x ;
        cout << getmax(1,n,l,r,x,1).se << '\n' ;
    }
    return 0 ;
}
