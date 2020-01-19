#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 6e5+9 ;
vector<int> cc ;
pii a[N];
ll st[N<<2],val[N],dp1[N],dp2[N];
vector<pair<pii,ll> > pp ;
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=dp1[l]+dp2[l];
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=max(st[m<<1],st[m<<1|1]);
}
ll getmax(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    return max(getmax(l,mid,x,y,m<<1),getmax(mid+1,r,x,y,m<<1|1));
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1,u,v ;i<=n;i++)
    {
        cin >> a[i].fi >> a[i].se >> val[i] ;
        cc.push_back(a[i].fi);
        cc.push_back(a[i].se);
    }
    sort(cc.begin(),cc.end());
    ///cc.resize(unique(cc.begin(),cc.end())-cc.begin());
    for(int i=1;i<=n;i++)
    {
        a[i].fi=lower_bound(cc.begin(),cc.end(),a[i].fi)-cc.begin()+1;
        a[i].se=lower_bound(cc.begin(),cc.end(),a[i].se)-cc.begin()+1;
        pp.push_back({{a[i].fi,a[i].se},val[i]});
    }
    sort(pp.begin(),pp.end(),[&](const pair<pii,ll> &a,const pair<pii,ll> b){
        return a.fi.se<b.fi.se;});
    for(int i=1,r=0;i<=2*n;i++)
    {
        dp1[i]=dp1[i-1];
        if(pp[r].fi.se==i&&r<n)dp1[i]=max(dp1[i],dp1[pp[r].fi.fi]+pp[r].se),r++;
    }
    sort(pp.begin(),pp.end(),[&](const pair<pii,ll> &a,const pair<pii,ll> b){
         return a.fi.fi<b.fi.fi;});
    for(int i=2*n,l=n-1;i>=1;i--)
    {
        dp2[i]=dp2[i+1];
        if(pp[l].fi.fi==i&&l>=0)
            dp2[i]=max(dp2[i],dp2[pp[l].fi.se]+pp[l].se),l--;
    }
    construct(1,2*n,1);
    ll ans = 0 ;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,getmax(1,2*n,a[i].fi+1,a[i].se-1,1)+val[i]);
    }
    cout << ans ;
    return 0 ;
}
