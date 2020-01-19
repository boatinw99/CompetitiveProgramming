#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 1e5+9 , MIN=-1e9 , MAX=1e9 ;
struct Tree
{
    int mn,mx ;
};
Tree st[N*4];
pii a[N];
vector<pii> sortx,sorty ;
map<int,int> mp ;
int L[N];
Tree operate(Tree t1,Tree t2)
{
    return {min(t1.mn,t2.mn),max(t1.mx,t2.mx)};
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]={l,l};
        return ;
    }
    construct(l,mid,m<<1),construct(mid+1,r,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
void update(int l,int r,int x,int cst1,int cst2,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m]={min(st[m].mn,cst1),max(st[m].mx,cst2)};
        return ;
    }
    update(l,mid,x,cst1,cst2,m<<1),update(mid+1,r,x,cst1,cst2,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
Tree findans(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return {MAX,MIN};
    if(l>=x&&r<=y)return st[m];
    return operate(findans(l,mid,x,y,m<<1),findans(mid+1,r,x,y,m<<1|1));
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,i,j ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i].fi ;
        mp[a[i].fi]=i ;
    }
    for(i=1;i<=n;i++)cin >> a[i].se ;
    sort(a+1,a+n+1);
    construct(1,n,1);
    for(i=1;i<=n;i++)
    {
        sortx.emplace_back(a[i].fi-a[i].se,i);
        sorty.emplace_back(a[i].fi+a[i].se,i);
    }
    sort(sortx.begin(),sortx.end());
    sort(sorty.begin(),sorty.end(),greater<pii>());
    for(auto it:sortx)
    {
        auto it1=lower_bound(a+1,a+1+n,make_pair(it.fi,0))-a;
        int tmp=findans(1,n,it1,it.se,1).mn;
        L[it.se]=tmp ;
        update(1,n,it.se,tmp,MIN,1);
    }
    for(auto it:sorty)
    {
        auto it1=upper_bound(a+1,a+1+n,make_pair(it.fi,0))-a-1;
        int tmp=findans(1,n,it.se,it1,1).mx;
        update(1,n,it.se,MAX,tmp,1);
    }
    int ans=0,tmp3=0;
    for(i=1;i<=n;i++)
    {
        int tmp1=findans(1,n,L[i],i,1).mx;
        int tmp2=findans(1,n,L[i],tmp1,1).mx;
        if(ans<tmp2-L[i]+1)ans=tmp2-L[i]+1,tmp3=mp[a[i].fi] ;
        if(ans==tmp2-L[i]+1&&mp[a[i].fi]<tmp3)tmp3=mp[a[i].fi];
    }
    cout << tmp3 << " " << ans ;
}
