#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
#define mid (l+r>>1)
const int N = 1e5+9 ; 
vector<ll> cc ; 
pii dp[N];
pii st[N<<2];
ll arr[N];
vector<int> ans ;
void update(int l,int r,int x,pii now,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m]=now ;
        return ;
    }
    update(l,mid,x,now,m<<1);
    update(mid+1,r,x,now,m<<1|1);
    st[m]=max(st[m<<1],st[m<<1|1]);
}
pii getmx(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return {0,0} ;
    if(l>=x&&r<=y)return st[m];
    return max(getmx(l,mid,x,y,m<<1),getmx(mid+1,r,x,y,m<<1|1));
}
void trace_back(int u)
{
    if(u==0)return ;
    ans.emplace_back(u);
    trace_back(dp[u].se);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,d ; 
    cin >> n >> d ;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i];
        cc.push_back(arr[i]);
    }
    sort(cc.begin(),cc.end());
    cc.resize(unique(cc.begin(),cc.end())-cc.begin());
    int m = cc.size();
    for(int i=1;i<=n;i++)
    {
        int l = upper_bound(cc.begin(),cc.end(),arr[i]-d)-cc.begin();
        int r = lower_bound(cc.begin(),cc.end(),arr[i]+d)-cc.begin()+1;
        pii mx = max(getmx(1,m,1,l,1),getmx(1,m,r,m,1));
        dp[i]={mx.fi+1,mx.se};
        update(1,m,lower_bound(cc.begin(),cc.end(),arr[i])-cc.begin()+1,{dp[i].fi,i},1);
    }
    pii mx = {0,0};
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,{dp[i].fi,i});
    }
    trace_back(mx.se);
    cout << ans.size() << '\n' ;
    for(int i=ans.size()-1;i>=0;i--)cout << ans[i] << " " ;
    return 0 ;
}